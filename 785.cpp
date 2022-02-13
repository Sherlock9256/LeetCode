#include<vector>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i = 0;i<graph.size();i++){
            if(color[i]==-1&&!help(graph,color,i,0)){
                return false;
            }
        }
        return true;
    }
    bool help(vector<vector<int>>& graph,vector<int>&color,int node,int cur_color){
        if(color[node]!=-1){
            return color[node]==cur_color;
        }
        color[node] = cur_color;

        for(auto& i : graph[node]){
            if(!help(graph,color,i,1-cur_color)){
                return false;
            }
        }
        return true;
    }
};