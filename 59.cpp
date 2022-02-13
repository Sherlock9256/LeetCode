#include <vector>
using namespace std;
class Solution {
    vector<vector<int>>* ret; 
public:
    vector<vector<int>> generateMatrix(int n) {
        ret = new vector<vector<int>>(n,vector<int>(n,0));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        help(visited,0,0,n,1,1);
        return *ret;
    }
    void help(vector<vector<bool>>& visited,int i,int j ,int n,int cur,int mode){
        if(0<=i&&i<n&&0<=j&&j<n&&!visited[i][j]){
            visited[i][j]=true;
            (*ret)[i][j]=cur;
            switch (mode)
            {
            case 1:
                help(visited,i,j+1,n,cur+1,1);
                help(visited,i+1,j,n,cur+1,2);
                break;
            case 2:
                help(visited,i+1,j,n,cur+1,2);
                help(visited,i,j-1,n,cur+1,3);
                break;
            case 3:
                help(visited,i,j-1,n,cur+1,3);
                help(visited,i-1,j,n,cur+1,4);
                break;
            case 4:
                help(visited,i-1,j,n,cur+1,4);
                help(visited,i,j+1,n,cur+1,1);
                break;
            default:
                break;
            }
        }
    }
};