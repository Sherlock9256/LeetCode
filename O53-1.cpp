#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = lower(nums,target);
        if(l<nums.size()&&nums[l]==target){
            int r = upper(nums,target);
            // cout<<l<<" "<<r<<endl;
            return r-l+1;
        }else{
            return 0;
        }
    }
    int lower(vector<int>& nums,int target){
        int l = 0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }

    int upper(vector<int>& nums,int target){
        int l = 0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(nums[mid]>target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};