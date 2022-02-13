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
    vector<int> ret;
    int cnt=0;
    int maxcnt=0;
    TreeNode* pre=nullptr;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ret;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(!pre){
            cnt++;
        }else if(pre->val==root->val){
            cnt++;
        }else{
            cnt=1;
        }
        if(cnt>maxcnt){
            maxcnt=cnt;
            ret.clear();
            ret.push_back(root->val);
        }else if(cnt==maxcnt){
            ret.push_back(root->val);
        }
        pre = root;
        inorder(root->right);
    }
};