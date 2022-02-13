#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> leftbound;
        int right;
        int len = postorder.size();
        int cur = len-2;
        int rightbound = INT_MAX;
        leftbound.push(postorder[len-1]);

        while(cur>=0){
            if(postorder[cur]>leftbound.top()){
                if(postorder[cur]<=rightbound){
                    leftbound.push(postorder[cur]);
                }else{
                    return false;
                }
            }else{
                while(postorder[cur]<=leftbound.top()){
                    rightbound = leftbound.top();
                    leftbound.pop();
                }
                leftbound.push(postorder[cur]);
            }
        }
        return true;
    }
};