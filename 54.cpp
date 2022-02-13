#include<vector>
using namespace std;
class Solution {
    vector<int> ret;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if(m==0)return ret;
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        help(matrix,visited,0,0,m,n,1);
        return ret;
    }
    void help(vector<vector<int>>& matrix,vector<vector<bool>>& visited,int i,int j,int m,int n,int mode){
        if(0<=i&&i<m&&0<=j&&j<n&&!visited[i][j]){
            visited[i][j]=true;
            ret.push_back(matrix[i][j]);
            switch (mode)
            {
            case 1:
                help(matrix,visited,i,j+1,m,n,1);
                help(matrix,visited,i+1,j,m,n,2);
                break;
            case 2:
                help(matrix,visited,i+1,j,m,n,2);
                help(matrix,visited,i,j-1,m,n,3);
                break;
            case 3:
                help(matrix,visited,i,j-1,m,n,3);
                help(matrix,visited,i-1,j,m,n,4);
                break;
            case 4:
                help(matrix,visited,i-1,j,m,n,4);
                help(matrix,visited,i,j+1,m,n,1);
                break;
            default:
                break;
            }
        }
    }
};