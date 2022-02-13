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
    bool isValidBST(TreeNode* root) {
        long left = INT_MIN;
        long right = INT_MAX;
        left--;
        right++;
        return help(root,left,right);
    }

    bool help(TreeNode* root,long leftmost,long rightmost){
        if(!root) return true;
        if((root->val>leftmost&&root->val<rightmost)){
            return help(root->left,leftmost,root->val)&&help(root->right,root->val,rightmost);
        }else{
            return false;
        }
    }
};