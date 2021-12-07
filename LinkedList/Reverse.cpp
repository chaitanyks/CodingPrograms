// Recursion

struct Node *reverseList(struct Node *head) {
    if (head->next != NULL) {
        Node *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }

    return head;
}

// Iterator 

struct Node *reverseList(struct Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *Next = head;
    while (curr != NULL) {
        Next = Next->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    return prev;
}
