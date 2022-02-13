#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0;i<nums.size();i++){
            while(nums[i]!=i+1&&nums[nums[i]]!=nums[i]+1){
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=i+1){
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};