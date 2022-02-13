class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        while(n){
            cnt += (n&1)==1?1:0;
        }
        return cnt==1;
    }
};