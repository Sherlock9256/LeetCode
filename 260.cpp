#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int cnt=0;
        for(auto& e:nums){
            cnt^=e;
        }
        cnt &= (-cnt);
        vector<int> ret(2,0);
        for(auto& e:nums){
            if((e&cnt)==0) ret[0]^=e;
            else ret[1]^=e;
        }
        return ret;
    }
};