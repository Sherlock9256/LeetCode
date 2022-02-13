#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        stack<TreeNode*> stk;
        bool order = true;
        stk.push(root);
        while(!stk.empty()){
            vector<int> cur_layer;
            stack<TreeNode*> newstk;
            while(!stk.empty()){
                TreeNode* cur = stk.top();
                stk.pop();
                if(!cur)continue;
                cur_layer.push_back(cur->val);
                if(order){
                    newstk.push(cur->left);
                    newstk.push(cur->right);
                }else{
                    newstk.push(cur->right);
                    newstk.push(cur->left);
                }
            }
            order = !order;
            stk=newstk;
            ret.push_back(cur_layer);
        }
        return ret;
    }
};