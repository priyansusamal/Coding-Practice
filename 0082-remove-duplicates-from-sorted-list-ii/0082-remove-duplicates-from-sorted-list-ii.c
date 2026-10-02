struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* current = head;

    while (current != NULL)
    {
        // Check if current is part of a duplicate group
        if (current->next != NULL &&
            current->val == current->next->val)
        {
            int duplicateValue = current->val;

            // Skip all nodes having this value
            while (current != NULL &&
                   current->val == duplicateValue)
            {
                current = current->next;
            }

            // Remove the entire duplicate group
            prev->next = current;
        }
        else
        {
            // Current value is unique
            prev = current;
            current = current->next;
        }
    }

    return dummy.next;
}