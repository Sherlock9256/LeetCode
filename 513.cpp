#include<iostream>
#include<queue>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que({root}) ;
        int ret = root->val;
        int cnt=1;
        while(que.size()>0){
            if(que.front()->left) que.push(que.front()->left);
            if(que.front()->right) que.push(que.front()->right);
            que.pop();
            cnt--;
            if(cnt==0&&que.size()>0){
                ret=que.front()->val;
                cnt=que.size();
            }
        }
        return ret;
    }
};