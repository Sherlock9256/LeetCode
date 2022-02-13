#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution_1 {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int pro = 0;
        int tmp = 0;
        int idx = 1;
        int size = prices.size();
        while(idx<size){
            if (prices[idx]<left){
                left = prices[idx];
            }else{
                tmp = prices[idx] - left;
                if (tmp > pro) pro = tmp;
            }
            idx++;
        }
        return pro;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int tmp;
        for(int i = 1;i<prices.size();i++){
            tmp = max(buy,sell-prices[i]);
            sell = max(buy+prices[i],sell);
            buy = tmp;
        }
        return sell;
    }
};