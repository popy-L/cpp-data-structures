#include <iostream>
using namespace std;
struct Node {
    int data;
    Node*next;
};

void InsertHead(Node*&head,int value) {
    Node* p=new Node;
    p->data=value;
    p->next=head;
    head=p;
}
int main() {
   Node* head=nullptr;
   for(int i=0;i<3;i++){
    InsertHead(head,i);
   }
Node* p=head;
while(p!=nullptr){
    cout<<p->data<<endl;
    p=p->next;
   }
};
