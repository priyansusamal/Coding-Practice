#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void backtrack(
    int* candidates,
    int candidatesSize,
    int target,
    int start,
    int* current,
    int currentSize,
    int** result,
    int* returnSize,
    int** returnColumnSizes
)
{
    // Target reached
    if (target == 0)
    {
        result[*returnSize] = malloc(currentSize * sizeof(int));

        for (int i = 0; i < currentSize; i++)
        {
            result[*returnSize][i] = current[i];
        }

        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;

        return;
    }

    for (int i = start; i < candidatesSize; i++)
    {
        // Skip duplicate values at the same level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Since array is sorted, no later value can work
        if (candidates[i] > target)
            break;

        // Choose
        current[currentSize] = candidates[i];

        // i + 1 because each number can be used only once
        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i + 1,
            current,
            currentSize + 1,
            result,
            returnSize,
            returnColumnSizes
        );
    }
}

int** combinationSum2(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
)
{
    *returnSize = 0;

    qsort(
        candidates,
        candidatesSize,
        sizeof(int),
        compare
    );

    /*
     * Maximum number of possible combinations
     * is bounded for the given constraints.
     */
    int maxResults = 10000;

    int** result = malloc(maxResults * sizeof(int*));

    *returnColumnSizes = malloc(maxResults * sizeof(int));

    int* current = malloc(candidatesSize * sizeof(int));

    backtrack(
        candidates,
        candidatesSize,
        target,
        0,
        current,
        0,
        result,
        returnSize,
        returnColumnSizes
    );

    free(current);

    return result;
}
