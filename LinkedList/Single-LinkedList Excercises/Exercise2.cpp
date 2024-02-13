#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* head;

void Print(struct Node* head) {
    struct Node* temp = head;
    cout << "List:" << endl;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Insertar nodo
struct Node* Insert(struct Node* head, int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

struct Node* Reverse(struct Node* head) {
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    int n, x;
    struct Node* head = NULL;
    cout << "Numbers: ?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Numero: " << endl;
        cin >> x;
        head = Insert(head, x);
        Print(head);
    }

    head = Reverse(head);
    Print(head);

    return 0;
}
