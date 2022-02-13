
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!(head&&head->next)) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                break;
            }
        }
        if(fast!=slow){
            return nullptr;
        }else{
            fast = head;
            while(fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }

    }
};