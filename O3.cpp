#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(nums[i]!=i&&nums[nums[i]]!=nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
            if(nums[i]==nums[nums[i]]){
                return nums[i];
            }
        }
    }
};