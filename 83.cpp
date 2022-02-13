
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        ListNode* tmp_next;
        int val=-101;
        while(tmp){
            val = tmp->val;
            tmp_next = tmp->next;
            while(tmp_next){
                if(tmp_next->val==val){
                    tmp_next = tmp_next->next;
                }else{
                    break;
                }
            }
            tmp->next = tmp_next;
            tmp = tmp->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        head->next = deleteDuplicates(head->next);
        
        return head->val==head->next->val?head->next:head;
    }
};