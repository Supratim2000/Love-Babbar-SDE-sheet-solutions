//Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return head;
        ListNode* p=nullptr;
        ListNode* q=head;
        ListNode* r=head->next;
        
        while(q)
        {
            q->next=p;
            p=q;
            q=r;
            if(r)
                r=r->next;
        }
        return p;
    }
};

//Recursive
class Solution {
public:
    ListNode* reverse(ListNode* head,ListNode* prev)
    {
        if(head==nullptr)
            return prev;
        ListNode* ans=reverse(head->next,head);
        head->next=prev;
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        return reverse(head,nullptr);
    }
};
