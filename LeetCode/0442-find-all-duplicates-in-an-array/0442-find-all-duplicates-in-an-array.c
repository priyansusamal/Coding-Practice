#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int num = abs(nums[i]);
        int index = num - 1;

        if (nums[index] < 0)
        {
            // Already seen → duplicate
            result[*returnSize] = num;
            (*returnSize)++;
        }
        else
        {
            // Mark as visited
            nums[index] = -nums[index];
        }
    }

    return result;
}
