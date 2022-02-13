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
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> inorder;
        vector<TreeNode*> inverinorder;
        TreeNode* pre=root;
        TreeNode* post=root;
        while(inorder.size()>0||inverinorder.size()>0||pre||post){
            while(pre){
                inorder.push_back(pre);
                pre = pre->left;
            }
            while(post){
                inverinorder.push_back(post);
                post = post->right;
            }
            post = inverinorder.back();
            pre = inorder.back();
            if(pre!=post){
                if(pre->val+post->val==k){
                    return true;
                }else if(pre->val+post->val>k){
                    inverinorder.pop_back();
                    post=post->left;
                }else{
                    inorder.pop_back();
                    pre=pre->right;
                }
            }else{
                return false;
            }
        }
    }
};