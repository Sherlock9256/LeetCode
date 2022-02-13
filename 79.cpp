#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        bool ret;
        vector<vector<int>> visited(m,vector<int>(n,0));
        int len = word.length();
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                ret = check(board,word,visited,0,len,i,j,m,n);
                if(ret){
                    return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board,string& word,vector<vector<int>>& visited,int idx,int len,int i,int j,int m,int n){
        if(0<=i&&i<m&&0<=j&&j<n&&visited[i][j]==0&&word[idx]==board[i][j]){
            visited[i][j]=1;
            if(idx==len-1){
                return true;
            }else{
                bool ret= check(board,word,visited,idx+1,len,i+1,j,m,n)||check(board,word,visited,idx+1,len,i-1,j,m,n)||check(board,word,visited,idx+1,len,i,j+1,m,n)||check(board,word,visited,idx+1,len,i,j-1,m,n);
                visited[i][j]=0;
                return ret;
            }
        }
        return false;
    }
};