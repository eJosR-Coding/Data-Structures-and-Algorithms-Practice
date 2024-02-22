#include "iostream"
using namespace std;

//Creando un nodo
struct Node {
    int data;
    struct Node* next;
};


//Variable global
struct Node* head;

void FindKthFromMiddle(int n){
    Node* fast = head, *slow = head, *mid = NULL;  
    int count = 0; // Initializing a variable to count the nodes from the middle

    // Find the middle node using the two-pointer approach
    while (fast && fast->next) {
        count++; // Increment count
        slow = slow->next; // Move slow one step
        fast = fast->next->next; // Move fast two steps
    }

    mid = slow; 
    fast = head, slow = head; 

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast != mid) {
        slow = slow->next;
        fast = fast->next;
    }
    cout<<"Value: "<<slow->data; 
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
  // Read the value of k from the user
    cout << "Enter the value of k to find the kth node from the middle: ";
    cin>>n;
    FindKthFromMiddle(n);
    
    return 0;
}
