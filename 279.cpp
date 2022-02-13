#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution_my {
public:
    int numSquares(int n) {
        vector<int> ret(n+1);
        int sq_idx = 1;
        int sq = sq_idx*sq_idx;
        int min_;
        for(int i = 1;i<n+1;i++){
            if(i==sq){
                ret[i]=1;
                sq_idx++;
                sq = sq_idx*sq_idx;
            }else{
                min_ = n+1;
                for(int j = i-1;j>0;j--){
                    min_ = min(ret[j]+ret[i-j],min_);
                    if(min_==2){
                        break;
                    }
                }
                ret[i]=min_;
            }
        }
        return ret[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
