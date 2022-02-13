#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur_max=0;
        int cur_len=0;
        for(auto& n:nums){
            if(n==1){
                cur_len++;
                cur_max=cur_len>cur_max?cur_len:cur_max;
            }else{
                cur_len=0;
            }
        }
        return cur_max;
    }
};