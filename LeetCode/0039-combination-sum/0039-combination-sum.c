#include <stdlib.h>

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
        // No point continuing if candidate is too large
        if (candidates[i] > target)
            continue;

        // Choose candidate
        current[currentSize] = candidates[i];

        // Same i because we can reuse the same number
        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i,
            current,
            currentSize + 1,
            result,
            returnSize,
            returnColumnSizes
        );
    }
}

int** combinationSum(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
)
{
    *returnSize = 0;

    // At most 150 combinations according to the problem
    int** result = malloc(150 * sizeof(int*));

    *returnColumnSizes = malloc(150 * sizeof(int));

    // Maximum possible combination length:
    // target / minimum candidate
    int* current = malloc((target + 1) * sizeof(int));

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
