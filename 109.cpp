
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next){
            return new TreeNode(head->val);
        }
        ListNode* mid = head;
        ListNode* fast = mid;
        ListNode* pre_mid;

        while(fast&&fast->next){
            pre_mid = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        TreeNode* ret = new TreeNode(mid->val);
        pre_mid->next = nullptr;
        ret->left = sortedListToBST(head);
        ret->right = sortedListToBST(mid->next);
        return ret;
    }
};