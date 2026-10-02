struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from the end
    struct ListNode* temp = slow->next;
    slow->next = temp->next;

    return dummy.next;
}
