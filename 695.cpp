#include<vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    ret = max(ret,cnt(grid,i,j,m,n));
                }
            }
        }
        return ret;
    }
    int cnt(vector<vector<int>>&grid,int i,int j,int m,int n){
        if(0<=i&&i<m&&0<=j&&j<n&&grid[i][j]==1){
            grid[i][j] = 0;
            return 1 + cnt(grid,i-1,j,m,n) + cnt(grid,i+1,j,m,n) + cnt(grid,i,j-1,m,n)+cnt(grid,i,j+1,m,n);
        }else{
            return 0;
        }
    }
};

int main(){
    vector<int> a={1};
    vector<vector<int>> b = {a};
    Solution s;
    s.maxAreaOfIsland(b);
}