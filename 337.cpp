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
    int rob(TreeNode* root) {
        int cnt;
        return help(root,cnt);
    }

    int help(TreeNode* root,int& son){
        if(!root){
            son = 0;
            return 0;
        } 
        int tmp = root->val;
        int left_s = 0;
        int right_s = 0;
        int left = help(root->left,left_s);
        int right = help(root->right,right_s);
        son = left+right;

        return max(left+right,left_s+right_s+tmp);
    }
};