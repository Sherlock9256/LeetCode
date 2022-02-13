#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int ret = nums.size();
        for(int i = 0;i<len;i++){
            ret^=i;
            ret^=nums[i];
        }
        return ret;
    }
};