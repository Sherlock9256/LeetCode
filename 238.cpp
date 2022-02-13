#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        int tmp = 1;
        ret[0] = tmp;
        for(int i = 1;i<nums.size();i++){
            ret[i] = ret[i-1]*nums[i-1];
        }
        tmp = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            ret[i] = ret[i]*tmp;
            tmp*=nums[i];
        }
        return ret;
    }
};