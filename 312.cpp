#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ret;
        ret = help(dp,0,n-1,nums);
        return ret;
    }
    int help(vector<vector<int>>& dp,int left,int right,vector<int>& nums){
        if(left>right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ret=0;
        int tmp = 0;
        int l_num,r_num;
        l_num = left==0?1:nums[left-1];
        r_num = right==nums.size()-1?1:nums[right+1];
        for(int i = left;i<=right;i++){
            tmp = nums[i]*l_num*r_num + help(dp,i+1,right,nums) + help(dp,left,i-1,nums);
            ret=ret>tmp?ret:tmp;
        }
        dp[left][right]=ret;
        return ret;
    }
};























class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n+2,vector<int>(n+2,0));
        return search(rec,nums,0,n+1,n);
    }
    int search(vector<vector<int>>& rec,vector<int>& nums,int left,int right,int n){
        if(left>=right-1){
            return 0;
        }
        if(rec[left][right]!=0)return rec[left][right];
        int max = 0,tmp;
        int left_num,right_num;
        left_num = left==0?1:nums[left-1];
        right_num = right==n+1?1:nums[right-1];
        for(int i = left+1;i<right;i++){
            tmp = left_num*right_num*nums[i-1] + search(rec,nums,left,i,n)+search(rec,nums,i,right,n);
            max = max>tmp?max:tmp;
        }
        rec[left][right]=max;
        return max;
    }
};

class Solution {
    int ret = 0;
public:
    int maxCoins(vector<int>& nums) {
        int max_len = nums.size();
        vector<unordered_map<int,int>> scores(max_len,unordered_map<int,int>());
        for(int i = 0;i<max_len;i++){
            scores[i][1] = nums[i];
            scores[i][0] = 1;
        }
        for(int len = 2;len<=max_len;len++){
            for(int i = 0;i<=max_len-len;i++){
                int ret = 0;
                int tmp;
                for(int left = 0;left<len;left++){
                    // if(left==0){
                    //     int p = 6;
                    // }
                    int idx = i+left;
                    int right = len-left-1;
                    // tmp = scores[i][left] * nums[idx] * scores[i+len-1-idx][right];
                    int add = 0;
                    tmp = nums[idx];
                    if(left>0){
                        tmp*=nums[idx-1];
                        add+=scores[i][left];
                    }
                    if(right>0){
                        tmp*=nums[idx+1];
                        add+=scores[idx+1][right];
                    }
                    tmp += add;
                    ret = ret>tmp?ret:tmp;
                    // cout<<i<<","<<len<<","<<left<<","<<tmp<<endl;
                }
                scores[i][len] = ret;
                cout<<i<<","<<len<<","<<ret<<endl;
            }
        }
        return scores[0][max_len];
    }
};
// class Solution {
//     int ret = 0;
// public:
//     int maxCoins(vector<int>& nums) {
//         vector<bool> dead(nums.size(),false);
//         for(int i =0;i<nums.size();i++){
//             if(nums[i]==0){
//                 dead[i]=true;
//             }
//         }
//         help(nums,0,dead);
//         return ret;
//     }
//     void help(vector<int>& nums,int sum,vector<bool>& dead){
//         cout<<sum<<",";
//         int pre = 1;
//         int next = 1;
//         int mul = 1;
//         int cur = 0;
//         bool found=false;
//         while(cur<nums.size()){
//             while(cur<nums.size()&&dead[cur]){
//                 cur++;
//             }
//             if(cur<nums.size()){
//                 //找到
//                 found = true;
//                 mul = pre * nums[cur];
//                 pre = nums[cur];
//                 next = cur+1;
//                 while(next<nums.size()&&dead[next]){
//                     next++;
//                 }
//                 if(next<nums.size()){
//                     mul*=nums[next];
//                 }
//                 dead[cur]=true;
//                 help(nums,sum+mul,dead);
//                 dead[cur]=false;
//                 cur = next;
//             }
//         }
//         if(!found){
//             ret = ret>sum?ret:sum;
//         }
//     }
// };
int main(){
    vector<int> a = {1,2,3};
    Solution s;
    s.maxCoins(a);
}