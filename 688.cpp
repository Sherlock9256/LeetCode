#include<vector>
using namespace std;
class Solution {
    vector<int> x={-2,-1,+1,+2,+2,+1,-1,-2};
    vector<int> y={+1,+2,+2,+1,-1,-2,-2,-1};
    double chi=0.125;
public:
    double knightProbability(int n, int k, int row, int column) {
        if(k==0)return 1;
        vector<vector<vector<double>>> dp(k,vector<vector<double>>(n,vector<double>(n,0)));
        for(int k_iter = 0;k_iter<k;k_iter++){
            for(int i = 0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int cnt=0;cnt<8;cnt++){
                        int x_b=i+x[cnt];
                        int y_b=j+y[cnt];
                        if(0<=x_b&&x_b<n&&0<=y_b&&y_b<n){
                            if(k_iter==0){
                                dp[k_iter][i][j] += chi;
                            }else{
                                dp[k_iter][i][j] += chi*dp[k_iter-1][x_b][y_b];
                            }
                        }
                    }
                }
            }
        }
        return dp[k-1][row][column];
    }
};
// class Solution {
//     vector<int> x={-2,-1,+1,+2,+2,+1,-1,-2};
//     vector<int> y={+1,+2,+2,+1,-1,-2,-2,-1};
//     double chi=0.125;
// public:
//     double knightProbability(int n, int k, int row, int column) {
//         int iter=0;
//         return help(n,k,row,column,iter);
//     }
//     double help(int n,int k,int row,int column,int iter){
//         if(0<=row&&row<n&&0<=column&&column<n){
//             if(iter<k){
//                 double cnt=0.;
//                 for(int i = 0;i<8;i++){
//                     cnt+=chi*help(n,k,row+x[i],column+y[i],iter+1);
//                 }
//                 return cnt;
//             }else{
//                 return chi;
//             }
//         }
//         return 0;
//     }
// };