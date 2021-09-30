//Using extra space
//Time complexity:- O(N)
//Space complexity:- O(N)
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

//Without using extra space
//Time complexity:- O(N)
//Space complexity:- O(1)
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    pair<Node*,int> reverse(struct Node *head)
    {
        pair<Node*,int> ans;
        int count=0;
        Node* p=nullptr;
        Node* q=head;
        Node* r=head->next;
        while(q)
        {
            count++;
            q->next=p;
            p=q;
            q=r;
            if(r)
                r=r->next;
        }
        ans.first=p;
        ans.second=count;
        return ans;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int sum;
        int carry=0;
        int res;
        pair<Node*,int> ll1=reverse(first);
        pair<Node*,int> ll2=reverse(second);
        int s1=ll1.second;
        int s2=ll2.second;
        first=ll1.first;
        second=ll2.first;
        if(s1<s2)
        {
            Node* temp=second;
            second=first;
            first=temp;
        }
        Node* p=first;
        Node* q=second;
        Node* prv=nullptr;
        while(p || q)
        {
            res=p->data+carry;
            if(q)
                res+=q->data;
            carry=res/10;
            sum=res%10;
            p->data=sum;
            prv=p;
            p=p->next;
            if(q)
                q=q->next;
        }
        if(carry)
        {
            Node* t=new Node(carry);
            prv->next=t;
        }
        return reverse(first).first;
    }
};
