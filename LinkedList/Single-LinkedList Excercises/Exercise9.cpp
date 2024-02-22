#include "iostream"
using namespace std;

//Creando un nodo
struct Node {
    int data;
    struct Node* next;
};


//Variable global
struct Node* head;


//Método de insertar
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

void Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int position, value;
    head =NULL;//Lista vacia
    Insert(7, 1);//List:2
    Insert(5, 2);//List:2,2
    Insert(3, 3);//List:2,2,3
    Insert(1, 4);//List:2,2,3,4
    //Print the original list
    cout << "Original list:" << endl;
    Print();
    //Inserting nodes at positions
    cout << "Position: "<<endl;
    cin >> position;
    cout<<"Value: "<<endl;
    cin>>value;

    Insert(value, position);
    cout << "Updated list: " << endl;
    Print();
    return 0;
}
