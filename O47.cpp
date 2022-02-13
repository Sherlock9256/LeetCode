#include<vector>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i = 1;i<m;i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int j = 0;j<n;j++){
            
        }
    }
};