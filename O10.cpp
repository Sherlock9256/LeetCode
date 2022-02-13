class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int prepre = 0;
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