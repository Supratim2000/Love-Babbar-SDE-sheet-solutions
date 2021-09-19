class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node* p=nullptr;
        Node* q=head;
        Node* r=head->next;
        while(q!=nullptr)
        {
            q->next=p;
            p=q;
            q=r;
            if(r!=nullptr)
                r=r->next;
        }
        return p;
    }
    
    Node *compute(Node *head)
    {
        Node* t=reverse(head);
        Node* dummy=new Node(0);
        Node* prev=dummy;
        while(t)
        {
            if(t->data>=prev->data)
            {
                prev->next=t;
                prev=t;
                t=t->next;
                prev->next=nullptr;
            }
            else
            {
                Node* temp=t;
                t=t->next;
                delete temp;
            }
        }
        return reverse(dummy->next);
    }
};
