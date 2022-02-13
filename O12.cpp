#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();
        cout<<m<<" "<<n<<" "<<len<<endl;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool ret = help(board,visited,word,0,len,i,j,m,n);
                    if(ret){
                        return ret;
                    }
                }
            }
        }
        return false;
    }

    bool help(vector<vector<char>>& board,vector<vector<bool>>& visited,string& w,int idx,int len,int i,int j,int m,int n){
        if(idx==len){
            return true;
        }
        if(0<=i&&i<m&&0<=j&&j<n&&!visited[i][j]&&board[i][j]==w[idx]){
            visited[i][j]=true;
            bool up = help(board,visited,w,idx+1,len,i-1,j,m,n);
            if(up)return true;
            bool down = help(board,visited,w,idx+1,len,i+1,j,m,n);
            if(down)return true;
            bool left = help(board,visited,w,idx+1,len,i,j-1,m,n);
            if(left)return true;
            bool right = help(board,visited,w,idx+1,len,i,j+1,m,n);
            if(right)return true;
            visited[i][j]=false;
            return false;
        }else{
            return false;
        }
    }
};