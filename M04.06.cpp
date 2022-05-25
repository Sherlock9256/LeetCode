class Solution {
    vector<TreeNode*> rec;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        help(root);
        for(int i =0;i<rec.size()-1;i++){
            if(rec[i]==p){
                return rec[i+1];
            }
        }
        return nullptr;
    }
    void help(TreeNode* root){
        if(!root)return ;
        help(root->left);
        rec.push_back(root);
        help(root->right);
    }
};