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
        
        int pos=l;
        int i=l,j=mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<nums[j]){
                tmp[pos]=nums[i];
                pos++;
                i++;
                cnt+= j-mid-1;
            }else{
                tmp[pos]=nums[j];
                pos++;
                j++;
            }
        }
        while(i<=mid){
            tmp[pos]=nums[i];
            pos++;
            i++;
            cnt+=j-mid-1;
        }
        while(j<=r){
            tmp[pos]=nums[j];
            pos++;
            j++;
        }
        copy(tmp.begin()+l,tmp.begin()+r+1,nums.begin()+l);
        // cout<<l<<","<<r<<","<<cnt<<endl;
        return cnt;
    }
};