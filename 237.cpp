
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre = node;
        ListNode* cur = node;
        do{
            pre = cur;
            cur = cur->next;
            pre->val=cur->val;
        }while(cur->next);
        pre->next=nullptr;
    }
};