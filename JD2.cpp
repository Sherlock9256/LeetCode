#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
class MSU{
    vector<int> rec;
public:
    MSU(int size){
        rec = vector<int>(size+1);
        for(int i=1;i<=size;i++){
            rec[i]=i;
        }
    }
    int find(int b){
        if(rec[b]!=b){
            rec[b]=find(rec[b]);
        }
        return rec[b];
    }
    void unite(int a,int b){
        rec[find(a)]=rec[find(b)];
    }
    bool united(int a,int b){
        return find(a)==find(b);
    }
};
bool check(vector<bool>& visited){
    for(auto a:visited){
        if(!a){
            return false;
        }
    }
    return true;
}
bool cmp(vector<int> a,vector<int> b){
    return a[2]>b[2];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    for(int i = 0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    sort(edges.begin(),edges.end(),cmp);
    // cout<<"---------"<<endl;
    MSU sets(n);
    int pre = edges[0][2];
    vector<bool> visited(n+1,false);
    for(int i = 0;i<m;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        // cout<<a<<" "<<b<<" "<<edges[i][2]<<endl;
        visited[a]=true;visited[b]=true;
        if(sets.united(a,b)){
            if(check(visited)){
                break;
            }
        }else{
            sets.unite(a,b);
            // cout<<a<<"->"<<sets.find(a)<<"\t"<<b<<"->"<<sets.find(b)<<endl;
            pre = edges[i][2];
        }
    }
    cout<<pre<<endl;
}