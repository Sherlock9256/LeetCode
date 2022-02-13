#include<vector>
using namespace std;
class Solution {
    int find(vector<int>& un,int i){
        return un[i]==i?i:(un[i]=find(un,un[i]));
    }
    void merge(vector<int>& un,int l,int r){
        un[find(un,l)]=find(un,r);
    }
    bool unin(vector<int>& un,int l,int r){
        return find(un,l)==find(un,r);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ret;
        int size = edges.size();
        vector<int> un(size+1);
        for(int i = 0;i<size+1;i++){
            un[i]=i;
        }
        for(auto& ele:edges){
            // cout<<"---"<<endl;
            // cout<<un[ele[0]]<<" "<<un[ele[1]]<<endl;
            if(unin(un,ele[0],ele[1])){
                return ele;
            }else{
                merge(un,ele[0],ele[1]);
            }
            // cout<<un[ele[0]]<<" "<<un[ele[1]]<<endl;
        }
        return ret;
    }
};