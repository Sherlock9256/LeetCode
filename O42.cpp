#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur =1;
        int len = nums.size();
        int ret = INT_MIN;
        while(cur<len){
            nums[cur] = max(nums[cur-1]+nums[cur],nums[cur]);
            ret = nums[cur]>ret?nums[cur]:ret;
            cur++;
        }
        return ret;
    }
};