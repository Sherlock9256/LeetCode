#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp=0;
        for(auto& a:nums){
            tmp^=a;
        }
        int cnt=0;
        while((tmp&1)==0){
            cnt++;
            tmp>>=1;
        }
        int tmp2=1;
        while(cnt){
            tmp2<<=1;
            cnt--;
        }
        int ret1=0,ret2=0;
        for(auto& a:nums){
            if((a&tmp2)==tmp2){
                ret1^=a;
            }else{
                ret2^=a;
            }
        }
        return {ret1,ret2};
    }
};