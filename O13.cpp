#include<vector>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int i = 0,j=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return 1 + help(m,n,i+1,j,k,visited) + help(m,n,i,j+1,k,visited);
    }
    int help(int m,int n,int i,int j,int k,vector<vector<bool>>& visited){
        if(0<=i&&i<m&&0<=j&&j<n&&!visited[i][j]&&check(i,j,k)){
            visited[i][j]=true;
            return 1+help(m,n,i+1,j,k,visited) + help(m,n,i,j+1,k,visited);
        }
        return 0;
    }
    bool check(int i,int j ,int k){
        int ret = 0;
        int mod;
        while(i){
            mod = i%10;
            ret+=mod;
            i/=10;
        }
        while(j){
            mod = j%10;
            ret+=mod;
            j/=10;
        }
        return ret<=k;
    }
};