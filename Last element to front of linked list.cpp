class Solution {
public:
    ListNode* rotateByOne(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* prv=nullptr;
        ListNode* nxt=head;
        while(nxt->next)
        {
            prv=nxt;
            nxt=nxt->next;
        }
        prv->next=nullptr;
        nxt->next=head;
        head=nxt;
        return head;
    }
};
