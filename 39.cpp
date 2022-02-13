#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_second{
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> comb;
        int sum = 0;
        search(ret,comb,candidates,sum,target,0);

        return ret;
    }

    void search(vector<vector<int>>& combs,vector<int>& comb,vector<int>& candidates,int sum, int target,int cur){
        for(int i = cur;i<candidates.size();i++){
            sum += candidates[i];
            comb.push_back(candidates[i]);
            if(sum == target){
                combs.push_back(comb);
            }else if(sum < target){
                search(combs,comb,candidates,sum,target,i);
            }else{
                comb.pop_back();
                return;
            }
            comb.pop_back();
            sum -= candidates[i];
        }
    }
};

int main(){
    vector<int> nums={2,3,6,7};
    int target = 7;
    Solution s;
    s.combinationSum(nums,target);
    
}