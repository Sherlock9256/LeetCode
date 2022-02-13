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
    bool isSymmetric(TreeNode* root) {
        return help(root,root);
    }
    bool help(TreeNode*a, TreeNode*b){
        if(!a&&!b) return true;
        if(!a||!b) return false;
        if(a->val==b->val){
            return help(a->left,b->right)&&help(a->right,b->left);
        }
        return false;
    }
};