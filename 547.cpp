#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ret = 0;
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(visited[i]==0){
                ret++;
                visit(isConnected,i,visited,n);
            }
        }
        return ret;
    }
    void visit(vector<vector<int>>& isConnected,int i,vector<int>& visited,int n){
        visited[i]=1;
        for(int j = 0;j<n;j++){
            if(i!=j){
                if(isConnected[i][j]&&visited[j]==0){
                    visit(isConnected,j,visited,n);
                }
            }
        }
    }
};