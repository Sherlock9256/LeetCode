#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ret;

void help(vector<int>& rec,vector<int>& tmp,int cnts,int idx){
    if(tmp.size()==cnts){
        ret.push_back(tmp);
        return;
    }
    for(int i=idx;i<rec.size();i++){
        tmp.push_back(rec[i]);
        help(rec,tmp,cnts,i+1);
        tmp.pop_back();
    }
}

int main(){
    vector<int> rec={0,1,2,3,4,5,6,7,8,9};
    int size = rec.size();
    vector<int> tmp;
    for(int i = 0;i<=size;i++){
        help(rec,tmp,i,0);
    }
    cout<<"ret size:"<<ret.size()<<endl;
    for(auto& p:ret){
        cout<<"size:"<<p.size()<<"\t";
        for(auto& a:p){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    return 0;
}