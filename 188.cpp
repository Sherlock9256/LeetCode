#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<int> buy(k,-prices[0]);
        vector<int> sell(k,0);

        int tmp_buy,tmp_sell;
        for(int i = 1;i<prices.size();i++){
            buy[0] = max(buy[0],-prices[i]);
            sell[0] = max(sell[0],buy[0]+prices[i]);
            for(int j =0;j<k;j++){
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[k] = max(sell[j],buy[j]+prices[j]);
            }
        }
        return sell[k-1];
    }
};