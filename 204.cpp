#include<vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> rec(n+1,false);
        int cnt=0;
        for(int i = 2;i<=n;i++){
            if(rec[i])continue;
            cnt++;
            for(long j = (long)(i)*i;j<n;j+=i){
                rec[j]=true;
            }
        }
        return cnt;
    }
};