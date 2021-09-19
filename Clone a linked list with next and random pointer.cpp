//Unoptimised(Using hashing)
//Time Complexity:- O(N)
//Space Complexity:- O(N)
class solution
{
    public:
    Node *copyList(Node *head)
    {
        unordered_map<Node*,Node*> randMp;
        Node* t=head;
        while(t)
        {
            Node* temp=new Node(t->data);
            randMp[t]=temp;
            t=t->next;
        }
        t=head;
        while(t)
        {
            if(t->next)
                randMp[t]->next=randMp[t->next];
            t=t->next;
        }
        t=head;
        while(t)
        {
            if(t->arb)
                randMp[t]->arb=randMp[t->arb];
            t=t->next;
        }
        return randMp[head];
    }
};

//Optimised
//Time Complexity:- O(N)
//Space Complexity:- O(1)
class solution
{
    public:
    Node *copyList(Node *head)
    {
        Node* t=head;
        Node* dummy=new Node(0);
        Node* prev=dummy;
        Node* ans=dummy;
        Node* p=head;
        Node* q=head->next;
        while(p)
        {
            Node* temp=new Node(p->data);
            p->next=temp;
            temp->next=q;
            p=p->next->next;
            if(q)
                q=q->next;
        }
        while(t)
        {
            if(t->arb)
                t->next->arb=t->arb->next;
            t=t->next->next;
        }
        p=head;
        q=head->next->next;
        while(p)
        {
            prev->next=p->next;
            prev=p->next;
            prev->next=nullptr;
            p->next=q;
            p=q;
            if(q)
                q=q->next->next;
        }
        ans=ans->next;
        delete dummy;
        return ans;
    }
};
