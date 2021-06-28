//Method 1
bool isCircular(Node *head)
{
    if(head==nullptr)
        return true;
    Node* slow=head;
    Node* fast=head;
    do
    {
        if(fast==nullptr || fast->next==nullptr)
            return false;
        slow=slow->next;
        if(fast || fast->next)
            fast=fast->next->next;
    }while(slow!=fast);
    return true;
}

//Method 2
bool isCircular(Node *head)
{
    if(head==nullptr)
        return true;
    Node* p=head->next;
    while(p!=head)
    {
        if(p==nullptr)
            return false;
        p=p->next;
    }
    return true;
}
