#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;

class Node
{
    public:
        ll val;
        Node* next;
        Node* prev;
        Node(ll val)
        {
            this->val=val;
            this->next=nullptr;
            this->prev=nullptr;
        }
};

void insert(Node** head, ll data)
{
    Node* temp=new Node(data);
    if(*head==nullptr)
        *head=temp;
    else
    {
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
    }
}

void show(Node* head)
{
    Node* h=head;
    while(h)
    {
        cout<<h->val<<"->";
        h=h->next;
    }
    cout<<"NULL"<<endl;
}


Node* rotateInGroupRecursive(Node* head,ll k)
{
    if(!head)
        return nullptr;
    Node* newHead=nullptr;
    Node* p=nullptr;
    Node* q=head;
    Node* r=head->next;
    ll count=0;
    while(q && count<k)
    {
        q->next=p;
        q->prev=r;
        if(r)
            r->prev=nullptr;
        p=q;
        q=r;
        if(r)
            r=r->next;
        newHead=p;
        count++;
    }
    if(!q)
        return newHead;
    else
    {
        Node* temp=rotateInGroupRecursive(q,k);
        head->next=temp;
        temp->prev=head;
        return newHead;
    }
}

int main()
{
    Node* head=nullptr;
    ll k=4;

    insert(&head, 10);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    show(head);
    Node* modifiedHead=rotateInGroup(head,k);
    cout<<"After rotation by "<<k<<" groups"<<": ";
    show(modifiedHead);

    return 0;
}
