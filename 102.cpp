#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        int cnt=1;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> tmp;
        while(que.size()){
            cnt--;
            tmp.push_back(que.front()->val);
            if(que.front()->left){
                que.push(que.front()->left);
            }
            if(que.front()->right){
                que.push(que.front()->right);
            }
            que.pop();
            if(cnt==0){ 
                ret.push_back(tmp);
                tmp.clear();
                cnt = que.size();
            }
        }
        return ret;
    }
};