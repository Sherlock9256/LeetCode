#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int left = 0;
        int right = 0;
        int idx = 1;
        int size = nums.size();
        int tmp = 0;
        while(idx<size){
            if(nums[idx]>=0){

            }else{

            }
            idx++;
        }
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
