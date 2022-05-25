#include<iostream>
#include<vector>
using namespace std;
void help(vector<vector<char>>& rec,vector<vector<int>>& move,int n,int m){
    char target='w';
    vector<vector<bool>> pre(n,vector<bool>(n,true));
    for(int m_idx=0;m_idx<m;m_idx++){
        vector<vector<bool>> cur(n,vector<bool>(n,true));
        int x=move[m_idx][0],y=move[m_idx][1];
        
        rec[x][y]=target;
        //转换
        target= target=='w'?'b':'w';

        int m_x=x,m_y=y;
        int rec_x=-1,rec_y=-1;
        //up
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_x--;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_x++;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_x++;
            }
        }
        //down
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_x++;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_x--;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_x--;
            }
        }
        //left
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y--;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y++;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y++;
            }
        }
        //right
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y++;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y--;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y--;
            }
        }
        //up_left
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y--;m_x--;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y++;m_x++;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y++;m_x++;
            }
        }
        //up_right
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y++;m_x--;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y--;m_x++;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y--;m_x++;
            }
        }
        //down_left
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y--;m_x++;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y++;m_x--;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y++;m_x--;
            }
        }
        //down_right
        m_x=x,m_y=y;
        rec_x=-1,rec_y=-1;
        while(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            if(rec[m_x][m_y]==target){
                rec_x=m_x;rec_y=m_y;
            }else if(rec[m_x][m_y]=='-'){
                break;
            }
            m_y++;m_x++;
        }
        m_x=rec_x,m_y=rec_y;
        if(m_x>=0&&m_x<n&&m_y>=0&&m_y<n){
            m_y--;m_x--;
            while(m_x!=x||m_y!=y){
                if(pre[m_x][m_y]){
                    rec[m_x][m_y]= rec[m_x][m_y]=='w'?'b':'w';
                    cur[m_x][m_y]= false;
                }
                m_y--;m_x--;
            }
        }
        //
        pre=cur;
    }
}
int main(){
    int T;cin>>T;
    for(int t_idx=0;t_idx<T;t_idx++){
        int n,m;cin>>n>>m;
        vector<vector<char>> rec(n,vector<char>(n,'.'));
        vector<vector<int>> move(m,vector<int>(2,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>rec[i][j];
//                 cout<<rec[i][j];
            }
//             cout<<endl;
        }
//         cout<<"--"<<endl;
        for(int i = 0;i<m;i++){
            cin>>move[i][0]>>move[i][1];
//             cout<<move[i][0]<<" "<<move[i][1]<<endl;
        }
        help(rec,move,n,m);
        //print
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<rec[i][j];
            }
            cout<<endl;
        }
        cout<<"END"<<endl;
    }
    return 0;
}