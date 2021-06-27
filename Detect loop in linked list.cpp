class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        do
        {
            if(fast==nullptr || fast->next==nullptr)
                return false;
                slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        return slow==fast?true:false;
    }
};
