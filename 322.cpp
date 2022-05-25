#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(auto& c:coins){
            if(c<amount+1){
                dp[c]=1;
            }
        }
        for(int i = 0;i<amount+1;i++){
            int tmp = INT_MAX;
            for(auto& c:coins){
                if(i-c>=0&&dp[i-c]!=-1){
                    tmp = tmp<dp[i-c]+1?tmp:dp[i-c]+1;
                }
            }
            if(tmp!=INT_MAX){
                dp[i]=tmp;
            }
        }
        return dp[amount];
    }
};








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