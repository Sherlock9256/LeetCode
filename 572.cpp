#include<algorithm>
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(sametree(root,subRoot)){
            return true;
        }else if(root){
            return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        }else{
            return false;
        }
    }

    bool sametree(TreeNode* root,TreeNode* subRoot){
        if(root&&subRoot&&root->val==subRoot->val){
            return sametree(root->left,subRoot->left)&&sametree(root->right,subRoot->right);
        }
        if(!root&&!subRoot) return true;
        return false;
    }
};