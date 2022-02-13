#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int l = 0,r = nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]>target){
                r--;
            }else if(nums[l]+nums[r]>target){
                l++;
            }else{
                ret.push_back(nums[l]);
                ret.push_back(nums[r]);
                break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ret;
        for(auto& a:nums){
            if(mp[target-a]!=0){
                ret.push_back(a);
                ret.push_back(target-a);
                break;
            }
            mp[a]++;
        }
        return ret;
    }
};