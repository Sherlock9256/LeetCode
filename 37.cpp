#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int>>> candidates(9,vector<vector<int>>(9));

        vector<vector<bool>> row_candi(9,vector<bool>(9,true));
        vector<vector<bool>> col_candi(9,vector<bool>(9,true));
        vector<vector<vector<bool>>> box_candi(3,vector<vector<bool>>(3,vector<bool>(9,true)));

        gen_candidates(row_candi,col_candi,box_candi,board);

        impute(row_candi,col_candi,box_candi,board,0,0);

    }

    bool impute(vector<vector<bool>>& row_candi,vector<vector<bool>>& col_candi,vector<vector<vector<bool>>>& box_candi,vector<vector<char>>& board,int idx_i,int idx_j){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(i<idx_i&&j<idx_j){
                    continue;
                }
                if(board[i][j]=='.'){
                    for(int cnt=0;cnt<9;cnt++){
                        if(row_candi[i][cnt]&&col_candi[j][cnt]&&box_candi[i/3][j/3][cnt]){
                            row_candi[i][cnt]=false;
                            col_candi[j][cnt]=false;
                            box_candi[i/3][j/3][cnt]=false;
                            board[i][j]='1'+cnt;
                            cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                            bool ok = impute(row_candi,col_candi,box_candi,board,i,j);
                            if(!ok){
                                cout<<"false "<<i<<" "<<j<<" "<<board[i][j]<<endl;
                                row_candi[i][cnt]=true;
                                col_candi[j][cnt]=true;
                                box_candi[i/3][j/3][cnt]=true;
                                board[i][j]='.';
                            }else{
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void gen_candidates(vector<vector<bool>>& row_candi,vector<vector<bool>>& col_candi,vector<vector<vector<bool>>>& box_candi,vector<vector<char>>& board){
        for(int i = 0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int tmp = board[i][j]-'1';
                    row_candi[i][tmp]=false;
                    col_candi[j][tmp]=false;
                    box_candi[i/3][j/3][tmp]=false;
                }
            }
        }
    }
};

int main(){
    vector<char> a1 = {'5','3','.','.','7','.','.','.','.'};
    vector<char> a2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> a3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> a4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> a5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> a6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> a7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> a8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> a9 = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char>> map = {a1,a2,a3,a4,a5,a6,a7,a8,a9};
    Solution s;
    s.solveSudoku(map);
}