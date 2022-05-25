#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
long help(long x,long y){
    unordered_map<long,bool> visited;
    long ret = 0;
    queue<long> que;
    que.push(x);
    long cnt=1;
    bool flag = false;
    visited[x]=true;
    while(!que.empty()){
        for(long i = 0;i<cnt;i++){
            long cur = que.front();
            if(cur==y){
                flag=true;
                break;
            }
            que.pop();
            visited[cur]=true;
            if(!visited.count(cur+1)){
                que.push(cur+1);
            }
            if(cur%3==0){
                if(cur>y){
                    if(!visited.count(cur/3)){
                        que.push(cur/3);
                    }
                }
            }
        }
        if(flag){
            break;
        }
        cnt = que.size();
        ret++;
    }
    return ret; 
}
int main(){
    int T;
    cin>>T;
    for(int _=0;_<T;_++){
        long x,y;cin>>x>>y;
        if(y>=x){
            cout<<y-x<<endl;
        }else{
            long ret =help( x, y);
            cout<<ret<<endl;
        }
    }
}