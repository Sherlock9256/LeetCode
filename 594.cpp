#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int ret = 0;
        int tmp;
        for(auto num:nums){
            mp[num]++;
            if(mp[num+1]!=0){
                tmp = mp[num] + mp[num+1];
                ret = tmp>ret?tmp:ret;
            }
            if(mp[num-1]!=0){
                tmp = mp[num] + mp[num-1];
                ret = tmp>ret?tmp:ret;
            }            
        }
        return ret;
    }
};