#include<iostream>
#include<vector>
using namespace std;

class Solution_my {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        return my_search(nums,target,left,right);
    }
    int my_search(vector<int>& nums, int target, int left, int right){
        
        int ret = -1;
        if(left<=right){
            int mid = left + (right-left)/2;
            if (nums[mid]>=nums[right]){
                if(nums[mid]>=target&&nums[left]<=target){
                    //found
                    right = mid;
                    while(left<=right){
                        mid = left + (right-left)/2;
                        if(nums[mid]>target){
                            right = mid-1;
                        }else if (nums[mid]<target){
                            left = mid+1;
                        }else{
                            ret = mid;
                            break;
                        }
                    }
                }else{
                    ret = my_search(nums,target,mid+1,right);
                }
            }else if (nums[mid]<nums[right]){
                if(nums[mid]<=target&&nums[right]>=target){
                    //found
                    left = mid;
                    while(left<=right){
                        mid = left + (right-left)/2;
                        if(nums[mid]>target){
                            right = mid-1;
                        }else if (nums[mid]<target){
                            left = mid+1;
                        }else{
                            ret = mid;
                            break;
                        }
                    }
                }else{
                    ret = my_search(nums,target,left,mid-1);
                }
            }
        }
        return ret;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int ret = s.search(nums,0);
    cout<<ret<<endl;
    return 0;
}