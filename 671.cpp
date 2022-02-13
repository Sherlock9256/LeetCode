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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root->left&&!root->right) return -1;
        if(root->left->val==root->right->val){
            int left = findSecondMinimumValue(root->left);
            int right = findSecondMinimumValue(root->right);
            if(left==-1) return right;
            if(right!=-1) return min(left,right);
            return left;
        }else if(root->left->val<root->right->val){
            int tmp = findSecondMinimumValue(root->left);
            if(tmp==-1) return root->right->val;
            else return min(root->right->val,tmp);
        }else{
            int tmp = findSecondMinimumValue(root->right);
            if(tmp==-1) return root->left->val;
            else return min(root->left->val,tmp);
        }
    }
};