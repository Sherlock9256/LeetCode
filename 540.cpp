#include<vector>
using namespace std;
class Solution_2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = nums[0];
        for(int i=1;i<nums.size();i++){
            ret = ret^nums[i];
        }
        return ret;
    }
};
class Solution_1 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left<right){
            mid = left + (right-left)/2;
            if(mid%2==0){
                //偶数
                if(nums[mid+1]==nums[mid]){
                    //在左边
                    left = mid+2;
                }else{
                    //在右边,并且可能是自己
                    right = mid;
                }
            }else{
                //奇数
                if(nums[mid-1]==nums[mid]){
                    //在左边
                    left = mid+1;
                }else{
                    //在右边
                    right = mid-1;
                }
            }
        }
        return nums[left];
    }
};
