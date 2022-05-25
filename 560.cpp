#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int pre = 0;
        for(auto& p:nums){
            p+=pre;
            pre = p;
            if(mp.count(p-k)){
                cnt+=mp[p-k];
            }
            mp[p]++;
        }
        return cnt;
    }
};

















class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int sum = 0;
        int ret = 0;
        mp[0]=1;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int tmp = sum-k;
            ret+=mp[tmp];
            mp[sum]++;
        }
        return ret;
    }
};