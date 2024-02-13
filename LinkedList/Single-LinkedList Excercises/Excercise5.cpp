#include <iostream>

using namespace std;

struct Node {
    int data;          // DATA
    struct Node* next;  // Next = LINK
};

struct Node* head; 

// Inserting Node at the Beginning
void Insert(int x) {
    struct Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Inserting Node at the End
void InsertEnd(int x) {
    struct Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        //We start by the beginning cos we can't acces to nth node, so we have to traverse the list
        struct Node* last = head;
        //and the lists goes updating till next(LINK) is null
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

// Function to print the linked list
void Print() {
    struct Node* temp = head;
    cout << "List: " << endl;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    head = NULL;
    Insert(1);
    Insert(3);
    Insert(5);
    Insert(7);
    Insert(9);
    Insert(11);
    Insert(13);
    InsertEnd(0);
    Print();
    return 0;
}
