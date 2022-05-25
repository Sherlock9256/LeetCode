#include<vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return 0;
        int ret = 0;
        int tmp_len = 2;
        int cnt=0;
        int diff = nums[1]-nums[0];
        for(int i = 2;i<n;i++){
            if(nums[i]-nums[i-1]==diff){
                tmp_len++;
                ret+=tmp_len-2;
            }else{
                tmp_len=2;
            }
            diff = nums[i]-nums[i-1];
        }
        return ret;
    }
};

















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