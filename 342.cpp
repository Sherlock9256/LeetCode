
class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt=0;
        while(n>0){
            cnt += (n&1)==1?1:0;
            if(cnt>1){
                break;
            }
            n>>=1;
            if((n&1)==1){
                cnt=0;
                break;
            }
            n>>=1;
        }
        return cnt==1;
    }
};
