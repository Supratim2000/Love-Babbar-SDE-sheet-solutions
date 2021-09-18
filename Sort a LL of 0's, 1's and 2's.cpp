class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* d0=new Node(INT_MIN);
        Node* d1=new Node(INT_MIN);
        Node* d2=new Node(INT_MIN);
        Node* p0=d0;
        Node* p1=d1;
        Node* p2=d2;
        Node* t=head;
        while(t)
        {
            if(t->data==0)
            {
                p0->next=t;
                p0=t;
                t=t->next;
                p0->next=nullptr;
            }
            else if(t->data==1)
            {
                p1->next=t;
                p1=t;
                t=t->next;
                p1->next=nullptr;
            }
            else
            {
                p2->next=t;
                p2=t;
                t=t->next;
                p2->next=nullptr;
            }
        }
        
        if(p0==d0 && p1==d1)
            return d2->next;
        else if(p1==d1 && p2==d2)
            return d0->next;
        else if(p0==d0 && p2==d2)
            return d1->next;
        else if(p0==d0)
        {
            p1->next=d2->next;
            return d1->next;
        }
        else if(p1==d1)
        {
            p0->next=d2->next;
            return d0->next;
        }
        else if(p2==d2)
        {
            p0->next=d1->next;
            return d0->next;
        }
        else
        {
            p0->next=d1->next;
            p1->next=d2->next;
            return d0->next;
        }
    }
};
