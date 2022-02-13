#include<vector>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        vector<vector<int>> rec(n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            rec[i][i]=1;
        }

        for(int len = 1;len<n;len++){
            for(int i = 0;i<n;i++){
                int right=i+len;
                if(right>n-1)break;
                int cur_max = len+1;
                if(i==0&&right==n-1)cur_max=0;
                int tmp = cur_max;
                for(int j=i;j<right;j++){
                    tmp = rec[i][j]*rec[j+1][right];
                    cur_max = cur_max>tmp?cur_max:tmp;
                }
                rec[i][right]=cur_max;
            }
        }
        return rec[0][n-1];
    }
};