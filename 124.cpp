#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int ret = 0;
public:
    int maxPathSum(TreeNode* root) {
        help(root);
        return ret;
    }
    int help(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = help(root->left);
        int right = help(root->right);
        int tmp = left + right + root->val;
        int tmp1 = left + root->val;
        int tmp2 = right + root->val;
        int tmp3 = root->val;

        ret = max(max(max(max(tmp,tmp1),tmp2),tmp3),ret);
        return max(max(left+root->val,right+root->val),root->val);
    }
};