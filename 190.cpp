#include<stdint.h>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int cnt = 32;
        while(cnt--){
            ret = ret << 1;
            ret+=(n&1);
            n = n>>1;
        }
        return ret;
    }
};