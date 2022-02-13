#include<iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        return help(root,false);
    }

    int help(TreeNode* root, bool left){
        if(!root) return 0;
        if(!root->left&&!root->right&&left){
            return root->val;
        }
        return help(root->left,true)+help(root->right,false);
    }
};