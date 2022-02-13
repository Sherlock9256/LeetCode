#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> mn(m+1,vector<int>(n+1,0));
        for(auto& str:strs){
            int zero = 0;
            int one = 0;
            for(auto& chr:str){
                one += chr-'0';
            }
            zero = str.length()-one;
            for(int i = m;i>=zero;i--){
                for(int j = n;j>=one;j--){
                    mn[i][j] = max(mn[i-zero][j-one]+1,mn[i][j]);
                }
            }   
        }
        return mn[m][n];
    }
};