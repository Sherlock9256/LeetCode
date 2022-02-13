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
    int min_ = INT_MAX;
    TreeNode* pre;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_;
    }

    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        if(pre){
            int tmp = root->val-pre->val;
            min_ = min_<tmp?min_:tmp;
        }
        pre = root;
        inorder(root->right);
    }
    
};


class Solution {
    int min_ = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        int left,right;
        help(root,left,right);
        return min_;
    }
    void help(TreeNode* node,int& left, int& right){
        if(!node->left&&!node->right){
            left=node->val;
            right=node->val;
            return;
        }
        left=right=node->val;
        int lleft,lright,tmp;
        if(node->left){
            help(node->left,lleft,lright);
            tmp = node->val-lright;
            min_ = min_<tmp?min_:tmp;
            left=lleft;
        }
        if(node->right){
            help(node->right,lleft,lright);
            tmp =lleft-node->val;
            min_ = min_<tmp?min_:tmp;
            right=lright;
        }
    }
};