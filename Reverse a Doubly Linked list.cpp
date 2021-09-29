// 3 Pointer method
//Time complexity:- O(N)
//Space complexity:- O(1)
Node* reverseDLL(Node * head)
{
    Node* p=nullptr;
    Node* q=head;
    Node* r=head->next;
    while(q)
    {
        q->next=p;
        q->prev=r;
        p=q;
        q=r;
        if(r)
            r=r->next;
    }
    return p;
}

// 2 Pointer method
//Time complexity:- O(N)
//Space complexity:- O(1)
Node* reverseDLL(Node * head)
{
    Node* p=nullptr;
    Node* q=head;
    while(q)
    {
        q->prev=q->next;
        q->next=p;
        p=q;
        q=q->prev;
    }
    return p;
}
