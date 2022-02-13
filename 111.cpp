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
    int min_ = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        help(root,0);
        return min_;
    }

    void help(TreeNode* root, int cur){
        if(!root) return;
        cur+=1;
        if(cur>=min_) return;
        if(!root->left&&!root->right){
            min_ = cur;
        }
        help(root->left,cur);
        help(root->right,cur);
    }
};