//Time complexity:- O(N*M)
//Space complexity:- O(1)
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* dummy=new Node(0);
    Node* prev=dummy;
    Node* p=head1;
    Node* q=head2;
    while(p && q)
    {
        if(p->data>=q->data)
        {
            prev->bottom=q;
            prev=q;
            q=q->bottom;
            prev->bottom=nullptr;
        }
        else
        {
            prev->bottom=p;
            prev=p;
            p=p->bottom;
            prev->bottom=nullptr;
        }
    }
    p?prev->bottom=p:prev->bottom=q;
    prev=dummy->bottom;
    delete dummy;
    return prev;
}

Node *flatten(Node *root)
{
    if(!root)
        return nullptr;
    Node* subProb=flatten(root->next);
    root->next=nullptr;
    return sortedMerge(root,subProb);
}
