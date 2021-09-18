//Brute force Approach
//Time complexity:- O(n)(Double pass)
//Space complexity:- O(1)
int getNthFromLast(Node *head, int n)
{
    Node* p=head;
    int size=0;
    while(p)
    {
        size++;
        p=p->next;
    }
    p=head;
    if(n>size)
        return -1;
    for(int i=n;i<size;i++)
        p=p->next;
    return p->data;
}

//Efficient Approach
//Time complexity:- O(n)(Single pass)
//Space complexity:- O(1)
int getNthFromLast(Node *head, int n)
{
    Node* f=head;
    Node* s=head;
    int i=0;
    for(;i<n && s;i++)
        s=s->next;
    if(i==n)
    {
        while(s)
        {
            s=s->next;
            f=f->next;
        }
        return f->data;
    }
    else
        return -1;
}
