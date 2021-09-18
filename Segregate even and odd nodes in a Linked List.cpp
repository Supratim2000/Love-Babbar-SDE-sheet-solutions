class Solution{
public:
    Node* divide(int N, Node *head){
        Node* d1=new Node(0);
        Node* d2=new Node(0);
        Node* p1=d1;
        Node* p2=d2;
        Node* t=head;
        for(int i=0;i<N;i++)
        {
            if((t->data)&1)
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
        if(p2==d2)
            return d1->next;
        p2->next=d1->next;
        return d2->next;
    }
};
