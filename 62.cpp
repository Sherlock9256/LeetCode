#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> up(n,0);
        int left = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                up[j]=left+up[j];
                left = up[j];
            }
            left = 0;
        }
        return up[n-1];
    }
};