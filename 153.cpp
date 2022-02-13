#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]<=nums[nums.size()-1]){
                //在右边
                right = mid-1;
            }else{
                //在左边
                left = mid+1;
            }
        }
        return nums[left];
    }
};