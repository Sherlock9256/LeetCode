#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int tmp=32;
        for(auto& num:nums){
            for(int i = 0;i<32;i++){
                bits[i]+=num&1;
                num>>=1;
            }
        }
        int ret=0;
        for(int i = 31;i>=0;i--){
            ret<<=1;
            bits[i]%=3;
            ret|=bits[i];
        }
        return ret;
    }  
};