#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 1;
        for(auto& coin:coins){
            for(int i = coin;i<=amount;i++){
                if(dp[i-coin]!=INT_MAX){
                    dp[i] = min(dp[i-coin]+1,dp[i]);
                }
            }
        }
        return dp[amount];
    }
};