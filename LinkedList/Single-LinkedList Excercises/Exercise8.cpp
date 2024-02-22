// Online C++ compiler to run C++ program online

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node*next;
};

struct Node* head;

void Insert(int x){
    Node* temp= new Node;
    temp->data=x;
    temp->next=head;
    head=temp;
}

void Print() {
    struct Node* temp = head;
    int pos = 1;
    cout << "List with Position:" << endl;
    while (temp != NULL) {
        cout << "Position " << pos << ": Data " << temp->data << endl;
        temp = temp->next;
        pos++;
    }
    cout << endl;
}

int main() {
    int n,x;
    head=NULL;
    Insert(1);
    Insert(3);
    Insert(5);
    Insert(7);
    Print();
    return 0;
}