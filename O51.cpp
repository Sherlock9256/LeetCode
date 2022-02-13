#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(nums.size());
        return merge(nums,tmp,0,n-1);
    }
    int merge(vector<int>&nums,vector<int>&tmp,int l,int r){
        if(l==r)return 0;
        int cnt = 0;
        int mid = l+(r-l)/2;
        cnt+= merge(nums,tmp,l,mid)+merge(nums,tmp,mid+1,r);

        int i=l,j=mid+1;
        while(i<=mid&&j<=r){
            
        }
    }
};