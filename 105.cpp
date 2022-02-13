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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0;
        int in = 0;
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        vector<TreeNode*> stk;
        stk.push_back(root);
        TreeNode* tmp1,*tmp2;
        while(pre<preorder.size()){
            while(stk.back()->val!=inorder[in]){
                tmp1 = new TreeNode(preorder[pre]);
                // cout<<preorder[pre]<<endl;
                stk.back()->left = tmp1;
                stk.push_back(tmp1);
                pre++;
            }
            if(pre>=preorder.size()){
                break;
            }
            // cout<<pre<<endl;
            while(!stk.empty()&&stk.back()->val==inorder[in]){
                in++;
                // cout<<in<<endl;
                tmp2 = stk.back();
                stk.pop_back();
            }
            // cout<<pre<<endl;
            tmp1 = new TreeNode(preorder[pre]);
            tmp2->right=tmp1;
            pre++;
            stk.push_back(tmp1);
        }
        return root;
    }
};