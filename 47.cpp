#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        vector<bool> visited(nums.size(),false);
        help(tmp,nums,visited,0);
        return ret;
    }
    void help(vector<int>& tmp,vector<int>& nums,vector<bool>& visited,int cnt){
        if(cnt==nums.size()){
            ret.push_back(tmp);
            return;
        }
        int pre=INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(visited[i]==true) continue;
            if(pre!=INT_MIN&&nums[i]==pre)continue;
            pre=nums[i];
            visited[i]=true;
            tmp.push_back(nums[i]);
            help(tmp,nums,visited,cnt+1);
            tmp.pop_back();
            visited[i]=false;
        }
    }
};

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