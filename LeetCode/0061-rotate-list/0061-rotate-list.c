struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct ListNode* tail = head;
    int length = 1;

    // Find the length and the last node
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Reduce unnecessary rotations
    k = k % length;

    if (k == 0) {
        return head;
    }

    // Connect the last node to the head
    tail->next = head;

    // Find the new tail
    int steps = length - k;
    struct ListNode* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Break the circular list
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
