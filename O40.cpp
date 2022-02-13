#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> que;
        for(auto& a:arr){
            que.push(a);
            if(que.size()>k)que.pop();
        }
        vector<int> ret;
        while(!que.empty()){
            ret.push_back(que.top());
            que.pop();
        }
        return ret;
    }
};