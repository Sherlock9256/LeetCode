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
    vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> cur;
        help(cur,root,target,0);
        return ret;
    }
    void help(vector<int>& cur,TreeNode* root,int target,int sum){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            if(sum+root->val==target){
                cur.push_back(root->val);
                ret.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(root->val);
        help(cur,root->left,target,sum+root->val);
        help(cur,root->right,target,sum+root->val);
        cur.pop_back();
    }
};