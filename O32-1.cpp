#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        if(!root)return ret;
        queue<TreeNode*> que;
        que.push(root);
        int cnt = 1;

        while(!que.empty()){
            for(int i = 0;i<cnt;i++){
                if(que.front()){
                    ret.push_back(que.front()->val);
                    que.push(que.front()->left);
                    que.push(que.front()->right);
                }
                que.pop();
            }
            cnt = que.size();
        }
        return ret;
    }
};