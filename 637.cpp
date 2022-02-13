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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> que;
        int cnt = 1;
        double tmp = cnt;
        double ave=0;
        que.push(root);
        while(que.size()>0){
            ave+=que.front()->val;
            if(que.front()->left)que.push(que.front()->left);
            if(que.front()->right)que.push(que.front()->right);
            que.pop();
            cnt--;
            if(cnt==0){
                ret.push_back(ave/tmp);
                ave=0;
                cnt=que.size();
                tmp = cnt;
            }
        } 
        return ret;
    }
};