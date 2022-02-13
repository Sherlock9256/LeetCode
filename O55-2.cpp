#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return help(root,depth);
    }
    bool help(TreeNode* root,int& depth){
        if(!root){
            depth=0;
            return true;
        }
        int leftdepth;
        bool left = help(root->left,leftdepth);
        if(left){
            int rightdepth;
            bool right = help(root->right,rightdepth);
            if(right){
                if(abs(leftdepth-rightdepth)<2){
                    depth = max(leftdepth,rightdepth)+1;
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};