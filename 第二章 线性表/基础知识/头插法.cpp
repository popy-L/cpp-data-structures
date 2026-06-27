#include <iostream>
using namespace std;
struct Node {
    int data;
    Node*next;
};

void claude(Node*&head,int value) {
    Node*p=new Node;
    p->data=value;
    p->next=head;
    head=p;
}
int main() {
    Node*head=nullptr;
    int a;
    claude(head,1);
    cout<<head->data<<endl;
};

