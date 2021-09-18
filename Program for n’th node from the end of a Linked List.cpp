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
