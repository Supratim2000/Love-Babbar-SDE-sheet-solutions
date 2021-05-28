/* Link list Node 
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

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    if(head==nullptr)
        return true;
    Node* slow=head;
    Node* fast=head;
    do
    {
        slow=slow->next;
        if(fast==nullptr || fast->next==nullptr)
            break;
        else
            fast=fast->next->next;
        if(fast==slow)
            return true;
    }while(true);
    return false;
}
