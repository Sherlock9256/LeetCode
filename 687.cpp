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
    int max_ = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int left = help(root->left,root->val);
        int right = help(root->right,root->val);
        int tmp = left+right;
        max_ = tmp>max_?tmp:max_;
        return max_;
    }

    int help(TreeNode* root, int previous){
        if(!root) return 0;
        int left = help(root->left,root->val);
        int right = help(root->right,root->val);
        int tmp = left+right;
        int ret = 0;
        if(root->val==previous){
            ret+=1; 
            ret += max(left,right);
        }else{
            max_ = tmp>max_?tmp:max_;
        }
        return ret;
    }
   
};