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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B){
            return false;
        }
        if(!same(A,B)){
            return isSubStructure(A->left,B)||isSubStructure(A->right,B);
        }else{
            return true;
        }

    }
    bool same(TreeNode*A,TreeNode*B){
        if(!B){
            return true;
        }
        if(!A){
            return false;
        }
        if(A->val!=B->val){
            return false;
        }
        return same(A->left,B->left)&&same(A->right,B->right);
    }
};