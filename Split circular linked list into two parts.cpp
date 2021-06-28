void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* start=head;
    Node* slow=head;
    Node* fast=head->next;
    
    while(fast!=start && fast->next!=start)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *head1_ref=start;
    *head2_ref=slow->next;
    slow->next=start;
    Node* p =*head2_ref;
    while(p->next!=start)
        p=p->next;
    p->next=*head2_ref;
}
