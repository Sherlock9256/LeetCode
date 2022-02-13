#include<iostream>
#include<queue>
#include<vector>
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
    TreeNode* convertBST(TreeNode* root) {
        int val=0;
        help(root,val);
        return root;
    }
    void help(TreeNode* root,int& val){
        if(!root) return;
        help(root->right,val);
        root->val+=val;
        val = root->val;
        help(root->left,val);
        return;
    }
};