#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

/* Insert at Head */
void insertAtHead(node* &head, int val) {
    node* n = new node(val);

    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

/* Insert at Tail */
void insertAtTail(node* &head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

/* Delete Head Node */
void deleteAtHead(node* &head) {
    if (head == NULL)
        return;

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

/* Delete at Given Position */
void deletion(node* &head, int pos) {
    if (head == NULL || pos <= 0)
        return;

    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Invalid position
    if (temp->next == head)
        return;

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

/* Display List */
void display(node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);

    deletion(head, 1);
    display(head);

    deletion(head, 10); // safe invalid delete
    display(head);

    return 0;
}
