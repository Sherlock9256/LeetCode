class Solution {
public:
    int numWays(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        int prepre = 1;
        int pre =1;
        int cur = 1;
        int tmp ;
        int mod = 1e9+7;
        while(cur<n){
            cur++;
            tmp = (prepre+pre)%mod;
            prepre = pre;
            pre = tmp;
        }
        return tmp;
    }
};