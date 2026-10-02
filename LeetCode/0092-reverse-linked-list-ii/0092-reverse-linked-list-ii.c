struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    if (head == NULL || left == right)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    // Move prev to the node just before 'left'
    struct ListNode* prev = &dummy;

    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    // Start reversing from 'left'
    struct ListNode* current = prev->next;

    // Reverse the section one node at a time
    for (int i = 0; i < right - left; i++)
    {
        struct ListNode* temp = current->next;

        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}
