#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *next;
};

Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *insertFront(Node *head, int data) {
    if (head == NULL) {
        head = newNode(data);
    } else {
        Node *x = newNode(data);
        x->next = head;
        head = x;
    }
    return head;


}

Node *insertLast(Node *head, int data) {
    if (head == NULL) {
        head = newNode(data);
    } else {
        Node *x = newNode(data);
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = x;
    }
    return head;
}

int main() {
    // your code goes here
    Node *head = NULL;
    Node *head1 = NULL;
    for (int i = 1; i <= 10; i++) {
        head = insertFront(head, i);
        head1 = insertLast(head1, i);
    }

    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head1;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
