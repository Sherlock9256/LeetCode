#include<vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        int pre = 0;
        int size = nums.size();
        for(int i = 2;i<size;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                pre = 1+pre;
                sum += pre;
            }else{
                pre = 0;
            }
        }
        return sum;
    }
};