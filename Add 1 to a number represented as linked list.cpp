class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* dummy=new Node(INT_MIN);
        Node* it=dummy;
        dummy->next=head;
        Node* prv=dummy;
        while(it)
        {
            if(it->data!=9)
                prv=it;
            it=it->next;
        }
        
        if(prv==dummy)
        {
            dummy->data=1;
            dummy=dummy->next;
            while(dummy)
            {
                dummy->data=0;
                dummy=dummy->next;
            }
            return prv;
        }
        
        if(prv->next==nullptr)
            prv->data+=1;
        else
        {
            prv->data+=1;
            prv=prv->next;
            while(prv)
            {
                prv->data=0;
                prv=prv->next;
            }
        }
        return head;
    }
};
