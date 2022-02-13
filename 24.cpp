
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* tmp = swapPairs(head->next->next);
        ListNode* tmp2 = head->next;
        tmp2->next = head;
        head->next = tmp;
        return tmp2;
    }
};
