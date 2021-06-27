class Solution
{
    public:
    void removeLoop(Node* head)
    {
        bool dontHaveLoop=false;
        Node* slow=head;
        Node* fast=head;
        do
        {
            if(fast==nullptr || fast->next==nullptr)
            {
                dontHaveLoop=true;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        if(dontHaveLoop)
            return;
        slow=head;
        if(slow==fast)
        {
            while(slow->next!=fast)
                slow=slow->next;
            slow->next=nullptr;
            return;
            
        }
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=nullptr;
    }
};
