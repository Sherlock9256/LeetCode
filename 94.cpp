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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        vector<int> ret;
        TreeNode* tmp = root;
        TreeNode* top;
        while(stk.size()>0||tmp){
            while(tmp){
                stk.push_back(tmp);
                tmp=tmp->left;
            }
            top = stk.back();
            stk.pop_back();
            ret.push_back(top->val);
            tmp = top->right;
        }
        return ret;
    }
};