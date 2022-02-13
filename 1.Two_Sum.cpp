#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> MytwoSum(vector<int>& nums, int target) {
        
        vector<int> ret ;
        vector<int> indices = nums;
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int sum = nums[l] + nums[r];
            if (target < sum)
            {
                r-- ;
            }
            else if (target > sum)
            {
                l++ ;
            }
            else
            {
                break;
            }
        }
        for (int idx = 0; idx < indices.size(); idx++)
        {
            if(indices[idx] == nums[l]||indices[idx] == nums[r])
            {
                ret.push_back(idx);
            }
        }
        return ret;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int,int> mp;
        for (int idx = 0; idx < nums.size(); idx++)
        {
             int sub = target - nums[idx];
             map<int,int>::iterator iter = mp.find(sub);
             if (iter != mp.end())
             {
                ret.push_back(iter->second);
                ret.push_back(idx);
             }
             mp[nums[idx]] = idx;
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {7,11,2,15};
    int target = 9;
    Solution s;
    vector<int> ret = s.twoSum(nums,target);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}

