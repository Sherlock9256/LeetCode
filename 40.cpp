#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> cur;
        search(ret,cur,candidates,target,0,0,candidates.size());
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,vector<int>& candidates,int target,int idx,int sum,int n){
        int tmp = -1;
        for(int i = idx;i<n;i++){
            if(tmp!=candidates[i]){
                tmp = candidates[i];
                sum+=candidates[i];
                cur.push_back(candidates[i]);
                if(sum==target){
                    ret.push_back(cur);
                    sum-=candidates[i];
                    cur.pop_back(); 
                    break;
                }else if(sum<target){
                    search(ret,cur,candidates,target,i+1,sum,n);
                    sum-=candidates[i];
                    cur.pop_back(); 
                }else{
                    sum-=candidates[i];
                    cur.pop_back();
                    break;
                }
            }
        }
    }
};

int main(){
    Solution  s;
    s.combinationSum2({10,1,2,7,6,1,5},8);
}