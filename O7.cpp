#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        int pre_idx=1,in_idx=0;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* tmp = root;
        vector<TreeNode*> stk;
        stk.push_back(root); 
        while(pre_idx<preorder.size()){
            while(!stk.empty()&&stk.back()->val!=inorder[in_idx]){
                tmp = new TreeNode(preorder[pre_idx]);
                stk.back()->left = tmp;
                stk.push_back(tmp);
                pre_idx++;
            }
            while(!stk.empty()&&stk.back()->val==inorder[in_idx]){
                tmp = stk.back();
                stk.pop_back();
                in_idx++;
            }
            if(pre_idx<preorder.size()){
                tmp->right = new TreeNode(preorder[pre_idx]);
                pre_idx++;
                stk.push_back(tmp->right);
            }
        }
        return root;
    }
};