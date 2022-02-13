#include<vector>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        if(grid.size()==1&&grid[0][0]==0){
            return 1;
        }
        vector<pair<int,int>> que;
        que.push_back({0,0});
        grid[0][0] = 1;
        int idx = 0;
        while(idx<que.size()){
            int idx_i = que[idx].first;
            int idx_j = que[idx].second;
            for(int i = -1;i<2;i++){
                if(idx_i+i>=0&&idx_i+i<grid.size()){
                    for(int j = -1;j<2;j++){
                        if(idx_j+j>=0&&idx_j+j<grid.size()){
                            if(grid[idx_i+i][idx_j+j]==0){
                                if(idx_i+i==grid.size()-1&&idx_j+j==grid.size()-1){
                                    return grid[idx_i][idx_j]+1;
                                }
                                grid[idx_i+i][idx_j+j] = grid[idx_i][idx_j]+1;
                                que.push_back({idx_i+i,idx_j+j});
                            }
                        }
                    }
                }
            }
            idx++;
        }
        return -1;
    }
};

int main(){

    vector<int> a={0,0,0};
    vector<int> b={1,1,0};
    vector<int> c={1,1,0};

    vector<vector<int>> ret = {a,b,c};
    Solution s ;
    s.shortestPathBinaryMatrix(ret);
}