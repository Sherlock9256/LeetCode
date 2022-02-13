#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> cur;
        search(ret,cur,nums,nums.size());
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,vector<int>& nums,int n){
        if(cur.size()==n){
            ret.push_back(cur);
        }else{
            int tmp = -50;
            for(int i = 0;i<n;i++){
                if(nums[i]!=-100&&nums[i]!=tmp){
                    tmp = nums[i];
                    cur.push_back(nums[i]);
                    nums[i]=-100;
                    search(ret,cur,nums,n);
                    nums[i] = cur.back();
                    cur.pop_back();
                }
            }
        }
    }
};