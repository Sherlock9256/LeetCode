#include<vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0)return false;
        int n = matrix[0].size();
        return help(matrix,0,0,m-1,n-1,target);
    }
    bool help(vector<vector<int>>& matrix,int x1,int y1,int x2,int y2,int target){
        if(x1==x2&&y1==y2){
            return matrix[x1][y1]==target;
        }
        if(x1>x2||y1>y2){
            return false;
        }
        int mid_x = x1+(x2-x1)/2;
        int mid_y = y1+(y2-y1)/2;
        int tmp = matrix[mid_x][mid_y];
        if(tmp==target){
            return true;
        }else if(tmp<target){
            return help(matrix,mid_x+1,y1,x2,mid_y,target)||help(matrix,x1,mid_y+1,mid_x,y2,target)||help(matrix,mid_x+1,mid_y+1,x2,y2,target);
        }else {
            return help(matrix,mid_x,y1,x2,mid_y-1,target)||help(matrix,x1,mid_y,mid_x-1,y2,target)||help(matrix,x1,y1,mid_x-1,mid_y-1,target);
        }
    }
};