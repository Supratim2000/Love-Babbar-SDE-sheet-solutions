#include<iostream>
#include<unordered_map>
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

ll countPair(Node* head, Node* tail, ll key)
{
    ll count=0;
    Node* l=head;
    Node* h=tail;
    while(l!=h && h->next!=l)
    {
        if(l->val==key-(h->val))
        {
            count++;
            l=l->next;
            h=h->prev;
        }
        else if(l->val<key-(h->val))
            l=l->next;
        else
            h=h->prev;
    }
    return count;
}

//Time complexity:- O(N^2)
//Space complexity:- O(1)
ll countTriplet(Node* head,ll key)
{
    ll count=0;
    if(head==nullptr)
        return count;
    Node* curr=head;
    Node* tail=head;
    while(tail->next)
        tail=tail->next;
    while(curr)
    {
        count+=countPair(curr->next,tail,key-(curr->val));
        curr=curr->next;        
    }
    return count;
}

//Time complexity:- O(N^2)
//Space complexity:- O(N)
ll countTripletHashing(Node* head,ll key)
{
    ll count=0;
    Node* h=head;
    unordered_map<ll,Node*> pres;
    while(h)
    {
        pres[h->val]=h;
        h=h->next;        
    }
    for(Node* p=head;p;p=p->next)
    {
        for(Node* q=p->next;q;q=q->next)
        {
            ll pairSum=p->val+q->val;
            if(pres.find(key-pairSum)!=pres.end())
            {
                if(pres[key-pairSum]!=p && pres[key-pairSum]!=q)
                    count++;
            }
        }
    }
    count/=3;
    return count;
}

int main()
{
    Node* head=nullptr;
    ll key=17;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    show(head);
    cout<<"Number of triplets: "<<countTriplet(head,key)<<endl;
    cout<<"Number of triplets using hashing: "<<countTripletHashing(head,key)<<endl;

    return 0;
}
