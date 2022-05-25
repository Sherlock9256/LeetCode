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
    int kthSmallest(TreeNode* root, int k) {
        return help(root,k);
    }
    int help(TreeNode* root,int& k){
        if(!root) return -1;
        int left = help(root->left,k);
        if(k==0)return left;
        k--;
        if(k==0)return root->val;
        int right = help(root->right,k);
        return right;
    }
};




class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return help(root,k);
    }

    int help(TreeNode* root, int& k) {
        if(!root) return -1;
        int left = help(root->left,k);
        if(k==0) return left;
        k--;
        if(k==0){
            return root->val;
        }
        int right=help(root->right,k);
        if(right==-1){
            return root->val;
        }
        return right;
    }
};
