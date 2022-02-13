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
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return help(root->left,root->right);
    }
    bool help(TreeNode* A,TreeNode* B){
        if(!A&&!B)return true;
        if(!A||!B)return false;
        if(A->val!=B->val) return false;
        return help(A->left,B->right)&&help(A->right,B->left);
    }
};