#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(auto& coin:coins){
            for(int i = coin;i<=amount;i++){
                dp[i] = dp[i-coin] + dp[i];
            }
        }
        return dp[amount];
    }
};