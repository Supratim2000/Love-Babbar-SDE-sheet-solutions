class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(struct Node *head)
    {
        Node* p=nullptr;
        Node* q=head;
        Node* r=head->next;
        while(q!=nullptr)
        {
            q->next=p;
            p=q;
            q=r;
            if(r)
                r=r->next;
        }
        return p;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node* p=first;
        Node* q=second;
        Node* dummy=new Node(-100);
        Node* remNode=nullptr;
        Node* newHead=nullptr;
        Node* prv=nullptr;
        Node* cur=dummy;
        int sum;
        int carry=0;
        int res;
        while(p && q)
        {
            res=(p->data)+(q->data)+carry;
            sum=res%10;
            carry=res/10;
            Node* t=new Node(sum);
            cur->next=t;
            prv=cur;
            cur=cur->next;
            p=p->next;
            q=q->next;
        }
        p?remNode=p:remNode=q;
        if(remNode)
        {
            while(remNode)
            {
                res=(remNode->data)+carry;
                sum=res%10;
                carry=res/10;
                Node* t=new Node(sum);
                cur->next=t;
                prv=cur;
                cur=cur->next;
                remNode=remNode->next;
            }
        }
        if(carry)
        {
            Node* t=new Node(carry);
            cur->next=t;
        }
        newHead=dummy->next;
        dummy->next=nullptr;
        delete dummy;
        newHead=reverse(newHead);
        return newHead;
    }
};
