#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string str="";
        search(ret,str,root);
        return ret;
    }

    void search(vector<string> &ret, string str,TreeNode* root){
        str = str + "->" + to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            ret.push_back(str.substr(2));
            return;
        }
        if(root->left){
            search(ret,str,root->left);
        }
        if(root->right){
            search(ret,str,root->right);
        }
    }
};