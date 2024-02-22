#include "iostream"
using namespace std;

//Creando un nodo
struct Node {
    int data;
    struct Node* next;
};


//Variable global
struct Node* head;

void DelNtheNd(int n){
    Node* slow=head;
    Node* fast=head;
    
    
      for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            cout << "N is greater than or equal to the length of the list" << endl;
            return;
        }
        fast = fast->next;
    }
    // If N is equal to the length of the list, delete the head
    if (fast == NULL) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
}


void Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
void Insert(int data, int n) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    
}

int main()
{
    int n,position, value;
    head =NULL;//Lista vacia
    Insert(9, 1);//List:2
    Insert(7, 2);//List:2,2
    Insert(5, 3);//List:2,2,3
    Insert(3, 4);//List:2,2,3,4
    Insert(1, 5);//List:2,2,3,4
    //Print the original list
    cout << "Original list:" << endl;
    Print();
    cout<<"Enter the end nth node to delete: "<<endl;
    cin>>n;
    DelNtheNd(n);
    Print();
    
    return 0;
}
