
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode* pre_slow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next){
            pre_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) {
            pre_slow=slow;
            slow=slow->next;
        }
        pre_slow->next = nullptr;

        ListNode* last = reverse(slow);

        while(slow&&head){
            if(slow->val!=head->val){
                return false;
            }
            slow=slow->next;
            head=head->next;
        }
        return true;
    
    }
    ListNode* reverse(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* ret = reverse(head->next);
        head->next->next = head;
        head->next=nullptr;
        return ret;
    }
};