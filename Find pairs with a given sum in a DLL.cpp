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

vector<pair<ll,ll>> findPair(Node* head, ll key)
{
    vector<pair<ll,ll>> ans;
    Node* l=head;
    Node* h=head;
    while(h->next)
        h=h->next;
    while(l!=h && h->next!=l)
    {
        if(l->val==key-(h->val))
        {
            ans.push_back({l->val,h->val});
            l=l->next;
            h=h->prev;
        }
        else if(l->val<key-(h->val))
            l=l->next;
        else
            h=h->prev;
    }
    return ans;
}

int main()
{
    Node* head=nullptr;
    ll key=7;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    show(head);
    vector<pair<ll,ll>> ans=findPair(head,key);
    if(ans.empty())
        cout<<"No pair found"<<endl;
    else
    {
        for(auto x: ans)
            cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }

    return 0;
}
