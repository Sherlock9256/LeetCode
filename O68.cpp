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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int tmp = (p->val-root->val)*(q->val-root->val);
        if(tmp<=0){
            return root;
        }
        if(p->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};