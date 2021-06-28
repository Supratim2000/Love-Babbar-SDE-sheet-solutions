class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head==nullptr || head->next==nullptr)
            return true;
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* p=slow;
        Node* q=slow->next;
        Node* r=slow->next->next;
        slow->next=nullptr;
        while(q)
        {
            q->next=p;
            p=q;
            q=r;
            if(r)
                r=r->next;
        }
        Node* lastHead=p;
        while(head)
        {
            if(head->data!=lastHead->data)
                return false;
            head=head->next;
            lastHead=lastHead->next;
        }
        return true;
    }
};
