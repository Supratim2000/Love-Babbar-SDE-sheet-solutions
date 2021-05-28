/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverseList(Node* head)
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
    Node* addOne(Node *head) 
    {
        Node* revHead=reverseList(head);
        Node* temp=revHead;
        Node* prev=nullptr;
        while(temp!=nullptr && temp->data==9)
        {
            temp->data=0;
            prev=temp;
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            Node* nd=new Node(1);
            prev->next=nd;
        }
        else
            temp->data+=1;
        return reverseList(revHead);
    }
};
