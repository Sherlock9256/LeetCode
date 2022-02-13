#include<vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> ret(n+1);
        ret[1]=1;
        int max = 0;
        int tmp;
        for(int i = 2;i<n+1;i++){
            max = 0;
            for(int j = 1;j<i;j++){
                tmp = ret[j]*(ret[i-j]);
                if(tmp>max){
                    max = tmp;
                }
            }
            ret[i]=max;
        }
        return ret[n];
    }
};