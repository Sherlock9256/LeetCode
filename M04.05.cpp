class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long leftmost = INT_MIN;
        leftmost--;
        long rightmost = INT_MAX;
        rightmost++;
        return help(root,leftmost,rightmost);
    }   
    bool help(TreeNode* root, long long  leftmost,long long  rightmost){
        if(!root)return true;
        if(root->val<rightmost&&root->val>leftmost){
            return help(root->left,leftmost,root->val)&&help(root->right,root->val,rightmost);
        }else{
            return false;
        }
    }
};