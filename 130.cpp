#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                mark(board,i,0,m,n);
            }
            if(board[i][n-1]=='O'){
                mark(board,i,n-1,m,n);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                mark(board,0,j,m,n);
            }
            if(board[m-1][j]=='O'){
                mark(board,m-1,j,m,n);
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]!='A'){
                    board[i][j]='X';
                }else{
                    board[i][j]='O';
                }
            }
        }
    }
    void mark(vector<vector<char>>& board,int i,int j,int m,int n){
        if(0<=i&&i<m&&0<=j&&j<n&&board[i][j]=='O'){
            board[i][j]='A';
            mark(board,i+1,j,m,n);
            mark(board,i-1,j,m,n);
            mark(board,i,j+1,m,n);
            mark(board,i,j-1,m,n);
        }
    }
};

int main(){
    vector<char> a = {'X','X','X','X'};
    vector<char> b = {'X','O','O','X'};
    vector<char> c = {'X','X','O','X'};
    vector<char> d = {'X','O','X','X'};
    vector<vector<char>> asd = {a,b,c,d};
    Solution s;
    s.solve(asd);

}