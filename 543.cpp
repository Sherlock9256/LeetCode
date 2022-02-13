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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth;
        return help(root,depth);
    }

    int help(TreeNode* root,int& depth){
        if(!root){
            depth = 0;
            return 0;
        }
        int leftdepth,rightdepth;
        int ret_l = help(root->left,leftdepth);
        int ret_r = help(root->right,rightdepth);
        depth = max(leftdepth,rightdepth)+1;
        return max(max(ret_l,ret_r),leftdepth+rightdepth);
    }
};