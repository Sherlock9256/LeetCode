#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i =0;i<t;i++){
        vector<long long> rec(5);
        cin>>rec[0]>>rec[1]>>rec[2]>>rec[3]>>rec[4];
        sort(rec.begin(),rec.end());
        long long cnt = 0;
//             for(auto& a:rec){
//                 cout<<a<<" ";
//             }
//             cout<<endl;
//             cout<<"--------"<<endl;
        while(rec[1]>0){
            long long tmp = rec[1]-rec[0] + 1;
            if(rec[0]==0)tmp-=1;
//             cout<<"tmp:"<<tmp<<endl;
            cnt += tmp;
            for(int j=1;j<5;j++){
                rec[j]-=tmp;
            }
            int j=0;
            while(j<4&&rec[j]>rec[j+1]){
                swap(rec[j],rec[j+1]);
                j++;
            }
//             for(auto& a:rec){
//                 cout<<a<<" ";
//             }
//             cout<<endl;
//             cout<<"--------"<<endl;
        }
        cout<<cnt<<endl;
    }
}