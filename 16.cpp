#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dis=INT_MAX;
        int ret;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-2;i++){
            if(i!=0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                while(l<r&&l!=i+1&&nums[l]==nums[l-1])l++;
                while(l<r&&r!=nums.size()-1&&nums[r]==nums[r+1])r--;
                if(l>=r)break;
                int tmp = nums[l]+nums[r]+nums[i];
                int diff = target-tmp;
                int abs_ = abs(diff);
                if(diff>0){
                    if(abs_<dis){
                        dis=abs_;
                        ret=tmp;
                    }
                    l++;
                }else if(diff<0){
                    if(abs_<dis){
                        dis=abs_;
                        ret=tmp;
                    }
                    r--;
                }else{
                    return tmp;
                }
            }
        }
        return ret;
    }
};