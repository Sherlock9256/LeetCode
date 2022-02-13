#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int& k) {
        if(!root)return -1;
        int right = kthLargest(root->right,k);
        if(k==0)return right;
        k--;
        if(k==0)return root->val;
        int left = kthLargest(root->left,k);
        return left;
    }
};