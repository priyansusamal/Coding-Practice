int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int sum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    return sum - actualSum;
}