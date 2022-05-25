#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    int n;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph,
     int start, int target) {
        unordered_map<int,unordered_map<int,bool>> mp;
        for(auto& p:graph){
            mp[p[0]][p[1]]=true;
        }
        vector<bool> visited(n,false);
        this->n=n;
        return help(visited,mp,start,target);
    }
    bool help(vector<bool>& visited,
    unordered_map<int,unordered_map<int,bool>>& mp,int start,int target){
        if(start==target)return true;
        visited[start]=true;
        bool find=false;
        for(auto& pb:mp[start]){
            if(visited[pb.first])continue;
            if(pb.second){
                find = help(visited,mp,pb.first,target);
                if(find){
                    break;
                }
            }
        }
        return find;
    }
};