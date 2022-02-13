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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int id=0;
        return help(root,p,q,id);
    }
    TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q,int& id){
        if(!root) return nullptr;
        int left=0,right=0;
        TreeNode* l=help(root->left,p,q,left);
        TreeNode* r=help(root->right,p,q,right);
        TreeNode* ret;
        if(left==2) return l;
        if(right==2) return r;
        id=left+right;
        if(root->val==p->val||root->val==q->val){
            id++;
        }
        return root;
    }
};