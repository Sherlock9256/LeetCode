#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution{
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        vector<int> stk;
        int len = nums.size();
        for(int i = 0;i<len;i++){
            while(!stk.empty()&&stk.back()<nums[i]){
                stk.pop_back();
            }
            stk.push_back(nums[i]);
            if(i>=k-1){
                ret.push_back(stk.back());
            }
        }
              
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int len = nums.size();
        // if(len<k){
        //     return ret;
        // }
        priority_queue<pair<int,int>,vector<pair<int,int>>> que;
        for(int i = 0;i<k-1;i++){
            que.push({nums[i],i});
        }
        int i = k;
        while(i<len){
            while(que.top().second<=i-k){
                que.pop();
            }
            que.push({nums[i],i});
            ret.push_back(que.top().second);
        }
        return ret;        
    }
};