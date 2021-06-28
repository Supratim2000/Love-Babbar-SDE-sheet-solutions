class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(true)
        {
            if(fast==nullptr || fast->next==nullptr)
                return slow;
            slow=slow->next;
            fast=fast->next->next;
        }
    }
};
