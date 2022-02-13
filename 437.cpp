#include<algorithm>
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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return fromroot(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
    int fromroot(TreeNode* root,int targ){
        if(!root) return 0;
        int cnt=0;
        if(root->val==targ) cnt++;
        cnt += fromroot(root->left,targ-root->val)+fromroot(root->right,targ-root->val);
        return cnt;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        vector<int> rec;
        int cnt = 0;
        help(root,targetSum,rec,cnt);
        return cnt;
    }
    void help(TreeNode* root, int& targ,vector<int>& rec,int& cnt){
        if(!root) return;
        rec.push_back(0);
        for(int i = 0;i<rec.size();i++){
            rec[i]+=root->val;
            if(rec[i]==targ)cnt++;
        }
        help(root->left,targ,rec,cnt);
        help(root->right,targ,rec,cnt);
        rec.pop_back();
        for(int i = 0;i<rec.size();i++){
            rec[i]-=root->val;
        }
    }
};