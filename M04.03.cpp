#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ret;
        queue<TreeNode*> que;
        que.push(tree);
        int cnt=1;


        while(!que.empty()){    
            ListNode* ltmp=new ListNode(-1);
            ListNode* Front = ltmp;
            TreeNode* ttmp;
            for(int i=0;i<cnt;i++){
                ttmp = que.front();
                que.pop();
                if(ttmp){
                    ltmp->next = new ListNode(ttmp->val);
                    ltmp=ltmp->next;
                    que.push(ttmp->left);
                    que.push(ttmp->right);
                }
            }
            cnt = que.size();
            if(Front->next){
                ret.push_back(Front->next);
            }
        }
        return ret;
    }
};