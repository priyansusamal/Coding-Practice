#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
    // Always binary search on the smaller array
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int m = nums1Size;
    int n = nums2Size;

    int low = 0;
    int high = m;

    while (low <= high)
    {
        int partition1 = (low + high) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0)
                       ? INT_MIN
                       : nums1[partition1 - 1];

        int minRight1 = (partition1 == m)
                        ? INT_MAX
                        : nums1[partition1];

        int maxLeft2 = (partition2 == 0)
                       ? INT_MIN
                       : nums2[partition2 - 1];

        int minRight2 = (partition2 == n)
                        ? INT_MAX
                        : nums2[partition2];

        // Correct partition
        if (maxLeft1 <= minRight2 &&
            maxLeft2 <= minRight1)
        {
            // Total number of elements is odd
            if ((m + n) % 2 != 0)
            {
                return (double)(
                    maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2
                );
            }

            // Total number of elements is even
            int leftMax = maxLeft1 > maxLeft2
                          ? maxLeft1
                          : maxLeft2;

            int rightMin = minRight1 < minRight2
                           ? minRight1
                           : minRight2;

            return (leftMax + rightMin) / 2.0;
        }

        // Move partition1 to the right
        if (maxLeft1 > minRight2)
        {
            high = partition1 - 1;
        }
        // Move partition1 to the left
        else
        {
            low = partition1 + 1;
        }
    }

    return 0.0;
}