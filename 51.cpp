#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution{
    vector<vector<string>> ret;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n,string(n,'.'));
        vector<bool> col(n,true);
        vector<bool> diag(n*2-1,true);
        vector<bool> undiag(n*2-1,true);
        help(cur,col,diag,undiag,0,n);
        return ret;
    }
    void help(vector<string>& cur,vector<bool>&col,vector<bool>& diag,vector<bool>& undiag,int idx,int n){
        if(idx==n){
            ret.push_back(cur);
            return;
        }
        for(int i = 0;i<n;i++){
            if(col[i]&&diag[i+idx]&&undiag[n-1-i+idx]){
                cur[idx][i]='Q';
                col[i]=false;
                diag[i+idx]=false;
                undiag[n-1-i+idx]=false;
                help(cur,col,diag,undiag,idx+1,n);
                cur[idx][i]='.';
                col[i]=true;
                diag[i+idx]=true;
                undiag[n-1-i+idx]=true;
            }
        }
    }
};

class Solution{
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n,true);
        vector<bool> diag(2*n-1,true);
        vector<bool> undiag(2*n-1,true);
        vector<vector<string>> ret;
        vector<string> cur(n,string(n,'.'));
        search(ret,cur,col,diag,undiag,n,0);
        return ret;
    }
    void search(vector<vector<string>>& ret,vector<string>& cur,vector<bool>& col,vector<bool>& diag,vector<bool>& undiag,int n,int idx){
        if(idx==n){
            ret.push_back(cur);
        }
        for(int i=0;i<n;i++){
            if(col[i]&&diag[i+idx]&&undiag[n-1-i+idx]){
                col[i]=false;
                diag[i+idx]=false;
                undiag[n-1-i+idx]=false;
                cur[idx][i]='Q';
                search(ret,cur,col,diag,undiag,n,idx+1);
                col[i]=true;
                diag[i+idx]=true;
                undiag[n-1-i+idx]=true;
                cur[idx][i]='.';
            }
        }
    }
};


class Solution_first {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<vector<int>> cur(n,vector<int>(n,0));

        search(ret,cur,n,n,0,0);
        return ret;
        
    }   
    
    void search(vector<vector<string>>& ret,vector<vector<int>>& cur,int left,int n,int idx_i,int idx_j){
        if(left==0){
            vector<string> tmp(n,string(n,'.'));
            int cnt = 0;
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cur[i][j]==n+1){
                        tmp[i][j]='Q';
                        cnt++;
                        if(cnt==n){
                            break;
                        }
                    }
                }
            }
            ret.push_back(tmp);
        }else{
            while(idx_i!=n){
                idx_i=idx_j==n-1?idx_i+1:idx_i;
                idx_j=idx_j==n-1?0:idx_j+1;
                if(cur[idx_i][idx_j]==0){
                    cout<<idx_i<<" "<<idx_j<<" marked"<<endl;
                    mark(cur,true,idx_i,idx_j,n);
                    search(ret,cur,left-1,n,idx_i,idx_j);
                    mark(cur,false,idx_i,idx_j,n);
                    cout<<idx_i<<" "<<idx_j<<" unmarked"<<endl;;
                }
            }
        }
    }

    void mark(vector<vector<int>>& cur, bool mark,int row ,int col,int n){
        //col
        for(int i=0;i<n;i++){
            if(cur[i][col]!=n+1){
                if(mark){
                    cur[i][col]++;
                }else{
                    cur[i][col]--;
                }
            }
        }
        //row
        for(int i=0;i<n;i++){
            if(cur[row][i]!=n+1){
                if(mark){
                    cur[row][i]++;
                }else{
                    cur[row][i]--;
                }
            }
        }
        //diag
        for(int i=row,j=col;0<=i&&i<n&&0<=j&&j<n;i++,j++){
            if(cur[i][j]!=n+1){
                if(mark){
                    cur[i][j]++;
                }else{
                    cur[i][j]--;
                }
            }
        }
        for(int i=row,j=col;0<=i&&i<n&&0<=j&&j<n;i--,j++){
            if(cur[i][j]!=n+1){
                if(mark){
                    cur[i][j]++;
                }else{
                    cur[i][j]--;
                }
            }
        }
        for(int i=row,j=col;0<=i&&i<n&&0<=j&&j<n;i++,j--){
            if(cur[i][j]!=n+1){
                if(mark){
                    cur[i][j]++;
                }else{
                    cur[i][j]--;
                }
            }
        }
        for(int i=row,j=col;0<=i&&i<n&&0<=j&&j<n;i--,j--){
            if(cur[i][j]!=n+1){
                if(mark){
                    cur[i][j]++;
                }else{
                    cur[i][j]--;
                }
            }
        }
        if(mark){
            cur[row][col]=n+1;
        }else{
            cur[row][col]=0;
        }
    }
};