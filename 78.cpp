#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        vector<vector<int>> ret;
        vector<int> cur;
        for(int i =0;i<=n;i++){
            search(ret,cur,nums,n,0,i);
        }
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,vector<int>& nums,int n,int idx,int size){
        if(cur.size()<size){
            for(int i =idx;i<n;i++){
                cur.push_back(nums[i]);
                search(ret,cur,nums,n,i+1,size);
                cur.pop_back();
            }
        }else{
            ret.push_back(cur);
        }
    }
};