class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* prev=head;
        ListNode* nex=head;
        while(nex)
        {
            while(nex && prev->val==nex->val)
                nex=nex->next;
            prev->next=nex;
            prev=nex;
        }
        return head;
        
    }
};
