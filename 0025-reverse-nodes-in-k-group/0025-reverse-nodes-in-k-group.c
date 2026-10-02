struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* groupPrev = &dummy;

    while (1)
    {
        // Find the kth node
        struct ListNode* kth = groupPrev;

        for (int i = 0; i < k; i++)
        {
            kth = kth->next;

            if (kth == NULL)
                return dummy.next;
        }

        // Node after the group
        struct ListNode* groupNext = kth->next;

        // Reverse the group
        struct ListNode* prev = groupNext;
        struct ListNode* current = groupPrev->next;

        while (current != groupNext)
        {
            struct ListNode* temp = current->next;

            current->next = prev;
            prev = current;
            current = temp;
        }

        // Connect previous part to reversed group
        struct ListNode* temp = groupPrev->next;
        groupPrev->next = kth;

        // Move groupPrev to the end of the reversed group
        groupPrev = temp;
    }

    return dummy.next;
}