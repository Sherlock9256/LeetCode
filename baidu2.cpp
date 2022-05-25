
#include<iostream>
#include<string>
#include<vector>
long long rec[1000000001][1000000001];
using namespace std;
int main(){
    while(1){
        long long a,b,x,y;
        cin>>a>>b>>x>>y;
        for(int i = 0;i<a+1;i++){
            for(int j = 0;j<b+1;j++){
                if(i-x>=0&&j-y>=0){
                    rec[i][j]=rec[i-x][j-y]+1;
                }
                if(i-y>=0&&j-x>=0){
                    rec[i][j]=max(rec[i][j],rec[i-y][j-x]+1);
                }
            }
        }
        cout<<rec[a][b]<<endl;
    }
}