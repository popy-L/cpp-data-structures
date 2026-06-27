void InsertTail(Node*& head, int value) {
    Node* p = new Node;
    p->data = value;
    p->next = nullptr;   //新节点是尾巴，所以 next 必须指向 nullptr！
    
    //如果链表为空，直接让 head = p
    if(head==nullptr){
        head=p;
    }
    //否则，找到最后一个节点，把 p 挂上去
    else{
        Node* tem=head;
        while(tem->next!=nullptr){
            tem=tem->next;
        }
        tem->next = p
    }
}
