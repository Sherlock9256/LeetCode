#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* l = mirrorTree(root->right);
        TreeNode* r = mirrorTree(root->left);
        root->left = l;
        root->right = r;
        return root;
    }
};