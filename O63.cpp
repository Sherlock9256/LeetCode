#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int have=-prices[0];
        int nohave=0;
        for(auto& a:prices){
            have = max(have,-a);
            nohave = max(nohave,have+a);
        }
        return nohave;
    }
};