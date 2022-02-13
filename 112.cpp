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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root,targetSum,0);
    }
    bool help(TreeNode* root,int targ,int sum){
        if(!root) return false;
        if(!root->left&&!root->right&&targ==sum+root->val){
            return true;
        }
        return help(root->left,targ,sum+root->val)||help(root->right,targ,sum+root->val);
    }
};