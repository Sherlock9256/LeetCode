#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    ret++;
                    mark(grid,i,j,m,n);
                }
            }
        }
        return ret;
    }
    void mark(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(0<=i&&i<m&&0<=j&&j<n&&grid[i][j]==1){
            grid[i][j]=0;
            mark(grid,i-1,j,m,n);
            mark(grid,i+1,j,m,n);
            mark(grid,i,j-1,m,n);
            mark(grid,i,j+1,m,n);
        }else{
            return;
        }
    }
};