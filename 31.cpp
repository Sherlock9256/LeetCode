#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution_my {
public:
    void nextPermutation(vector<int>& nums) {
        int end = nums.size()-1;
        int idx = nums.size()-2;
        int tmp;
        while(idx>=0){
            //bi-search
            int left = idx+1;
            int right = end;
            int mid;
            while(left<=right){
                mid = left + (right-left)/2;
                if(nums[mid]<=nums[idx]){
                    left = mid+1;
                }else if(nums[mid]>nums[idx]){
                    right = mid-1;
                }
            }
            if(left<=end){
                //found
                int tmp = nums[left];
                nums[left] = nums[idx];
                nums[idx] = tmp;
                break;   
            }
            idx--;
            sort(nums.begin()+idx+1,nums.end());
        }
    }
};


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


int main(){
    vector<int> nums = {1,5,1};
    Solution s;
    s.nextPermutation(nums);
}