#include<vector>
using namespace std;
class Solution {
    vector<int> ret;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses,vector<int>());
        for(auto& ele:prerequisites){
            pre[ele[0]].push_back(ele[1]);
        }
        vector<int> studied(numCourses,0);// 0:unstudied；1：to；2：studied

        for(int i = 0;i<numCourses;i++){
            if(studied[i]==0){
                if(!help(pre,i,studied)){
                    ret.clear();
                    break;
                }
            }
        }
        return ret;
    }
    bool help(vector<vector<int>>& pre,int cur,vector<int>& studied){
        studied[cur]=1;
        for(auto& p:pre[cur]){
            if(studied[p]==2){
                continue;
            }else if(studied[p]==1){
                return false;
            }else if(!help(pre,p,studied)){
                return false;
            }
        }
        studied[cur]=2;
        ret.push_back(cur);
        return true;
    }
};