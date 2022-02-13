#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> stk;
        TreeNode* tmp;
        stk.push_back(root);
        while(stk.size()>0){
            tmp = stk.back();
            stk.pop_back();
            if(!tmp) continue;
            ret.push_back(tmp->val);
            stk.push_back(tmp->left);
            stk.push_back(tmp->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};