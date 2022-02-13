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
    bool isBalanced(TreeNode* root) {
        int depth;
        return help(root,depth);
    }

    bool help(TreeNode* root,int& depth){
        if(!root){
            depth=0;
            return true;
        }
        int left_depth,right_depth;
        bool ret;
        if(help(root->left,left_depth)&&help(root->right,right_depth)&&abs(left_depth-right_depth)<2){
            ret = true;
        }else{
            ret = false;
        }
        depth = max(left_depth,right_depth)+1;

        return ret;
    }
};