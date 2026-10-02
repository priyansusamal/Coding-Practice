#include <stdlib.h>

typedef long long ll;

typedef struct Node
{
    ll val;
    int index;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct
{
    ll sum;
    int index;
    Node* left;
} Pair;

typedef struct
{
    Pair* data;
    int size;
} MinHeap;

int smaller(Pair a, Pair b)
{
    if (a.sum != b.sum)
        return a.sum < b.sum;

    return a.index < b.index;
}

void swap(Pair* a, Pair* b)
{
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, Pair pair)
{
    int i = heap->size++;
    heap->data[i] = pair;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (!smaller(heap->data[i], heap->data[parent]))
            break;

        swap(&heap->data[i], &heap->data[parent]);
        i = parent;
    }
}

Pair pop(MinHeap* heap)
{
    Pair result = heap->data[0];

    heap->size--;

    if (heap->size > 0)
    {
        heap->data[0] = heap->data[heap->size];

        int i = 0;

        while (1)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heap->size &&
                smaller(heap->data[left], heap->data[smallest]))
            {
                smallest = left;
            }

            if (right < heap->size &&
                smaller(heap->data[right], heap->data[smallest]))
            {
                smallest = right;
            }

            if (smallest == i)
                break;

            swap(&heap->data[i], &heap->data[smallest]);
            i = smallest;
        }
    }

    return result;
}

void addPair(MinHeap* heap, Node* left)
{
    if (left == NULL || left->next == NULL)
        return;

    Pair pair;

    pair.sum = left->val + left->next->val;
    pair.index = left->index;
    pair.left = left;

    push(heap, pair);
}

int minimumPairRemoval(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return 0;

    Node* nodes = malloc(numsSize * sizeof(Node));

    MinHeap heap;
    heap.data = malloc(3 * numsSize * sizeof(Pair));
    heap.size = 0;

    /* Build doubly linked list */
    for (int i = 0; i < numsSize; i++)
    {
        nodes[i].val = nums[i];
        nodes[i].index = i;

        nodes[i].prev = (i > 0)
                        ? &nodes[i - 1]
                        : NULL;

        nodes[i].next = (i < numsSize - 1)
                        ? &nodes[i + 1]
                        : NULL;
    }

    /* Count decreasing adjacent pairs */
    int bad = 0;

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nodes[i].val > nodes[i + 1].val)
            bad++;
    }

    /* Add all adjacent pairs */
    for (int i = 0; i < numsSize - 1; i++)
    {
        addPair(&heap, &nodes[i]);
    }

    int operations = 0;

    while (bad > 0)
    {
        Pair pair;

        /*
         * Remove stale heap entries.
         *
         * A valid pair must:
         * 1. Still have a right neighbour.
         * 2. Have the same current sum.
         */
        while (1)
        {
            pair = pop(&heap);

            Node* left = pair.left;

            if (left->next != NULL &&
                left->val + left->next->val == pair.sum)
            {
                break;
            }
        }

        Node* left = pair.left;
        Node* right = left->next;

        Node* before = left->prev;
        Node* after = right->next;

        /* Remove old decreasing pairs */

        if (before != NULL &&
            before->val > left->val)
        {
            bad--;
        }

        if (left->val > right->val)
        {
            bad--;
        }

        if (after != NULL &&
            right->val > after->val)
        {
            bad--;
        }

        /* Merge left + right */

        left->val += right->val;
        left->next = after;

        if (after != NULL)
        {
            after->prev = left;
        }

        /*
         * IMPORTANT:
         * right has been removed from the list.
         * Clear its links so old heap entries
         * involving right become invalid.
         */
        right->prev = NULL;
        right->next = NULL;

        /* Add new decreasing pairs */

        if (before != NULL &&
            before->val > left->val)
        {
            bad++;
        }

        if (after != NULL &&
            left->val > after->val)
        {
            bad++;
        }

        /* Add updated adjacent pairs */

        addPair(&heap, before);
        addPair(&heap, left);

        operations++;
    }

    free(heap.data);
    free(nodes);

    return operations;
}