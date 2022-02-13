#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int m=0;
        int ret = INT_MAX;
        int tmp;
        for(auto& p:mp){
            if(p.second.size()>m){
                m=p.second.size();
                tmp = p.second.back()-p.second.front()+1;
                ret = tmp;
            }else if(p.second.size()==m){
                tmp = p.second.back()-p.second.front()+1;
                ret = tmp<ret?tmp:ret;
            }
        }
        return ret;
    }
};