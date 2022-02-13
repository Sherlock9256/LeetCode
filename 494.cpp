#include<vector>
using namespace std;
class Solution_1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums,target,0,0,nums.size());
    }

    int find(vector<int>& nums,int target,int cur,int idx,int size){
        if(idx==size){
            if(target==cur) return 1;
            else return 0;
        }
        int l,r;
        l = find(nums,target,cur+nums[idx],idx+1,size);
        r = find(nums,target,cur-nums[idx],idx+1,size);
        return l+r;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto& e:nums){
            sum+=e;
        }
        int W = (target+sum)/2;
        vector<int> cap(W+1,0);
        cap[0] = 1;
        for(auto& e:nums){
            for(int i = W;i>=e;i--){
                cap[i] = cap[i-e]>0?cap[i-e]:0 + cap[i];
            }
        }
        return cap[W];
    }
};