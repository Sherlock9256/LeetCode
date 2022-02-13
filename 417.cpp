#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ret;
        vector<vector<int>> left(m,vector<int>(n,0));
        vector<vector<int>> right(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0||j==0){
                    check(left,heights,heights[i][j],i,j,m,n);
                }
                if(i==m-1||j==n-1){
                    check(right,heights,heights[i][j],i,j,m,n);
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(left[i][j]==right[i][j]==1){
                    ret.push_back(vector<int>{i,j});
                }
            }
        }
        return ret;
    }
    void check(vector<vector<int>>& map_,vector<vector<int>>& heights,int height,int i ,int j ,int m ,int n){
        if(0<=i&&i<m&&0<=j&&j<n&&map_[i][j]==0&&height<=heights[i][j]){
            map_[i][j]=1;
            check(map_,heights,heights[i][j],i-1,j,m,n);
            check(map_,heights,heights[i][j],i+1,j,m,n);
            check(map_,heights,heights[i][j],i,j-1,m,n);
            check(map_,heights,heights[i][j],i,j+1,m,n);
        }
    }
};
class Solution_wrong {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> ret;
        bool left = false;
        bool right = false;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                check(heights,visited,heights[i][j],i,j,m,n);
                if(visited[i][j]==3){
                    vector<int> tmp = {i,j};
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }

    int check(vector<vector<int>>& heights,vector<vector<int>>& visited,int last,int i ,int j ,int m, int n ){
        if(0<=i&&i<m&&0<=j&&j<n&&heights[i][j]<=last){
            if(visited[i][j]==0){
                visited[i][j]=-1;
                bool left = false;
                bool right = false;
                int a = check(heights,visited,heights[i][j],i-1,j,m,n);
                if(a==1)left=true;
                if(a==2)right=true;
                if(a==3)left=right=true;
                a = check(heights,visited,heights[i][j],i+1,j,m,n);
                if(a==1)left=true;
                if(a==2)right=true;
                if(a==3)left=right=true;
                a = check(heights,visited,heights[i][j],i,j-1,m,n);
                if(a==1)left=true;
                if(a==2)right=true;
                if(a==3)left=right=true;
                a = check(heights,visited,heights[i][j],i,j-1,m,n);
                if(a==1)left=true;
                if(a==2)right=true;
                if(a==3)left=right=true;
                if(left&&right){
                    visited[i][j]=3;
                }else if(right){
                    visited[i][j]=2;
                }else if(left){
                    visited[i][j]=1;
                }else{
                    if(i==0||j==0){
                        visited[i][j] = 1;
                    }
                    if(i==m-1||j==n-1){
                        visited[i][j] = 2;
                    }
                    if((i=0&&j==n-1)||(i==m-1&&j==0)){
                        visited[i][j] = 3;
                    }
                }
            }
            return visited[i][j];
        }else{
            return -1;
        }
    }
};