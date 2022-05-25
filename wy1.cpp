#include<vector>
#include<iostream>
#include<deque>
#include<climits>
#include<algorithm>
using namespace std;
int help(vector<long long>& rec,vector<char>& flag,int n,int k){
    vector<long long> b_two(n);
    vector<long long> b_five(n);
    vector<long long> r_two(n);
    vector<long long> r_five(n);
    for(int i = 0;i<n;i++){
        long long t=0,f=0;
        long long cur = rec[i];
        while(cur%2==0){
            cur/=2;
            t++;
        }
        cur=rec[i];
        while(cur%5==0){
            cur/=5;
            f++;
        }
        if(i==0){
            if(flag[i]=='R'){
                r_two[i]=t;r_five[i]=f;
                b_two[i]=0;b_five[i]=0;
            }else{
                r_two[i]=0;r_five[i]=0;
                b_two[i]=t;b_five[i]=f;
            }
        }else{
            if(flag[i]=='R'){
                r_two[i]=r_two[i-1]+t;
                r_five[i]=r_five[i-1]+f;
                b_two[i]=b_two[i-1];
                b_five[i]=b_five[i-1];
            }else{
                r_two[i]=r_two[i-1];
                r_five[i]=r_five[i-1];
                b_two[i]=b_two[i-1]+t;
                b_five[i]=b_five[i-1]+f;
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        cout<<r_two[i]<<" ";
    }
    cout<<endl<<"------"<<endl;
        for(int i = 0;i<n;i++){
        cout<<r_five[i]<<" ";
    }
    cout<<endl<<"------"<<endl;
        for(int i = 0;i<n;i++){
        cout<<b_two[i]<<" ";
    }
    cout<<endl<<"------"<<endl;
        for(int i = 0;i<n;i++){
        cout<<b_five[i]<<" ";
    }
    cout<<endl<<"------"<<endl;
    int l=0,r=0;
    int cur_k=0;
    int ret = INT_MAX;
    while(r<n){
        long long rt,rf,bt,bf;
        if(l==0){
            rt = r_two[r];
            rf = r_five[r];
            bt = b_two[r];
            bf = b_five[r];
        }else{
            rt = r_two[r]-r_two[l-1];
            rf = r_five[r]-r_five[l-1];
            bt = b_two[r]-b_two[l-1];
            bf = b_five[r]-b_five[l-1];
        }
        cur_k = min(rf,rf)+min(bt,bf);
        if(cur_k>=k){
            ret = min(ret,l-r+1);
            l++;
        }else{
            r++;
        }
    }
    return ret;
}
int main(){
    int n,k;cin>>n>>k;
    vector<long long> rec(n);
    for(int i =0;i<n;i++)cin>>rec[i];
    vector<char> flag(n);
    for(int i =0;i<n;i++)cin>>flag[i];
    int ret = help(rec,flag,n,k);
    cout<<ret<<endl;
}