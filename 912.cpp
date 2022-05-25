#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        help(nums,0,nums.size()-1);
        return nums;
    }
    void help(vector<int>& nums,int l,int r){
        if(l<=r)return;
        int pivot=l;
        while(l<r){
            while(l<r&&nums[l]<=nums[pivot]){
                l++;
            }
            while(l<r&&nums[r]>nums[pivot]){
                r--;
            }
            swap(nums[l],nums[r]);
        }
        swap(nums[l],nums[pivot]);
        help(nums,l,pivot-1);
        help(nums,pivot+1,r);
    }
};