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
