class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1&&t2)return false;
        bool s = same(t1,t2);
        if(s)return s;
        return checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2);
    }
    bool same(TreeNode* t1,TreeNode* t2){
        if(!t1&&!t2){
            return true;
        }else if (t1&&t2){
            if(t1->val==t2->val){
                return same(t1->left,t2->left)&&same(t1->right,t2->right);
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};