#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int had = -prices[0];
        int sold = 0;
        int dead = 0;
        for(int i = 1;i<prices.size();i++){
            int p = prices[i];
            int tmphad = max(had,sold-p);
            int tmpsold = max(dead,sold);
            int tmpdead = had+p;
            had = tmphad;
            sold = tmpsold;
            dead = tmpdead;
        }
        return max(sold,dead);
    }
};










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