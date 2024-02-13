// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
struct Node{
    int data; //DATA 
    struct Node* next;//Next=LINK
};
struct Node* head;

//Inserting Node
void Insert(int x){
    struct Node* temp=new Node;
    temp->data=x;
    temp->next=head;
    head=temp;
};
void Print(){
    struct Node* temp=head;
    cout<<"List: "<<endl;
    while(temp!=NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
        
    }
    cout<<endl;
}
//Count Node
void Count(){
    Node* temp=head;
    int ctr=0;
    
    while(temp!=NULL){
        ctr++;
        temp=temp->next;
    }
    
    cout<<"Total nodes: "<<ctr<<endl;
};
int main() {
    head=NULL;
    int n,x;
    cout<<"howmnodes?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"number: "<<endl;
        cin>>x;
        Insert(x);
        Print();
      
    }
  Count();
    return 0;
}