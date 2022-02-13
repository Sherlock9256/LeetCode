#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int still;
        int none;
        for(int i = 1;i<prices.size();i++){
            still = buy+prices[i];
            none = max(none,still); 
            buy = max(buy,none-prices[i]);
        }
        return max(none,still);
    }
};