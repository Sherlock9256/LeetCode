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

class Solution{
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return search(1,n);
    }
    vector<TreeNode*> search(int l ,int r){
        vector<TreeNode*> ret;
        if(l>r){
            ret.push_back(nullptr);
            return ret;
        }

        for(int i = l;i<=r;i++){
            vector<TreeNode*> left = search(l,i-1);
            vector<TreeNode*> right = search(i+1,r);
            for(auto& l:left){
                for(auto& r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};

class Solution_wrong {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        vector<int> inserted(n);
        for(int i = 0;i<n;i++){
            if(i==1){
                int p =0;
            }
            TreeNode* root = new TreeNode(i+1);
            inserted[i]=1;
            search(ret, root,inserted,n);
            inserted[i]=0;
        }
        return ret;
    }
    void search(vector<TreeNode*>& ret, TreeNode* root,vector<int> inserted,int n){
        //或者复制？
        bool isinsert = false;
        for(int i = 0;i<n;i++){
            if(!inserted[i]){
                TreeNode* leaf = new TreeNode(i+1);
                insert(root,leaf);
                inserted[i]=1;
                search(ret,root,inserted,n);
                del(root,leaf);
                inserted[i]=0;
                isinsert = true;
            }
        }
        if(!isinsert){
            //指针
            ret.push_back(copy(root));
        }
    }
    void insert(TreeNode* root,TreeNode* leaf){
        if(root->val<leaf->val){
            if(root->right==nullptr){
                root->right = leaf;
            }else{
                insert(root->right,leaf);
            }
        }else{
            if(root->left==nullptr){
                root->left=leaf;
            }else{
                insert(root->left,leaf);
            }
        }
    }
    void del(TreeNode* root,TreeNode* leaf){
        if(root->val<leaf->val){
            if(root->right->val==leaf->val){
                root->right=nullptr;
            }else{
                del(root->right,leaf);
            }
        }else{
            if(root->left->val==leaf->val){
                root->left=nullptr;
            }else{
                del(root->left,leaf);
            }
        }
    }
    TreeNode* copy(TreeNode* root){
        TreeNode* ret = new TreeNode(root->val);
        copy_help(ret,root);
        return ret;
    }
    void copy_help(TreeNode* ret, TreeNode* root){
        if(root->left){
            TreeNode* left = new TreeNode(root->left->val);
            ret->left = left;
            copy_help (ret->left,root->left);
        }
        if(root->right){
            TreeNode* right = new TreeNode(root->right->val);
            ret->right = right;
            copy_help (ret->right,root->right);
        }
    }
};

int main(){
    Solution s;
    int n = 3;
    s.generateTrees(n);
}