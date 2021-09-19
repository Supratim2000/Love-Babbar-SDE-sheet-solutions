//Unoptimised
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
