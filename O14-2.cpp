#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    unordered_map<int,int> len2cnt;
    int tot;
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        long ret=1;
        int mod = 1000000007;
        while(n>4){
            ret = ret*3%mod;
            n-=3;
        }
        return (int)(ret*n%mod);
    }
};