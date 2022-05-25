#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_first_time {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};

        int l = 0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]>=target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(l==nums.size()||nums[l]!=target){
            return ret;
        }
        ret[0]=l;
        
        l=0,r=nums.size()-1;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ret[1]=r;
        return ret;
    }
};

class Solution_first_time {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};

        int left = 0,right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if(left<nums.size()&&nums[left]==target){
            ret[0] = left;
            //found
            right = nums.size()-1;
            while(left<=right){
                mid = left + (right-left)/2;
                if(nums[mid]<=target){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            ret[1] = right;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        vector<int> ret;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]>=target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        if(left>=nums.size()||nums[left]!=target){
            ret.push_back(-1);
            ret.push_back(-1);
        }else{
            ret.push_back(left);
            left = 0;
            right = nums.size()-1;
            while(left<right){
                mid = left +(right-left)/2;
                if(nums[mid]>target){
                    right=mid;
                }else{
                    left = mid+1;
                }
            }
            ret.push_back(right-1);
        }
        return ret;
    }
};