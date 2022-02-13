#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int idx = 1;
        int left = prices[0];
        int right;
        int size = prices.size();
        while(idx<size){
            right = prices[idx];
            if(right>left){
                pro += right-left;
            }
            left = right;
            
            idx++;
        }
        return pro;
    }
};