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
    void flatten(TreeNode* root) {
        if(root) {
            help(root);
        }
    }
    TreeNode* help(TreeNode* root){
        if(root->left){
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* tail = help(root->right);
            if(tmp){
                tail->right = tmp;
                return help(tmp);
            }else{
                return tail;
            }
        }else if(root->right){
            return help(root->right);
        }else{
            return root;
        }
    }
};