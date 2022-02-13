#include<vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i<target+1;i++){
            for(auto& num:nums){
                if(i>=num&&dp[i-num]>0){
                    dp[i] = dp[i] + dp[i-num];
                }
            }
        }
        return dp[target];
    }
};