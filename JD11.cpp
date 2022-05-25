#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
long long m_Cnt = 1000000000000000000;
long long help(long long x,long long y,vector<bool>& size){
    if(size[x])return m_Cnt-1;
    size[x]=true;
    if(x<y)return y-x;
    if(x==y)return 0;
    long long a=m_Cnt;
    long long b=m_Cnt;

    if(x%3==0){
        b = 1+help(x/3,y,size);
        if(x/3<y){
            a = 1+help(x+1,y,size);
        }
    }else{
        a = 1+help(x+1,y,size);   
    }
    return min(a,b);
}
int main(){
    int T;
    cin>>T;
    for(int _=0;_<T;_++){
        vector<bool> size(m_Cnt,false);
        long long x,y;cin>>x>>y;
        long long ret = help(x,y,size);
        cout<<ret<<endl;
    }
}