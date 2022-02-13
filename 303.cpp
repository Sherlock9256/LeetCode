#include<vector>
using namespace std;
class NumArray {
public:
    vector<int>& sums;
    NumArray(vector<int>& nums):sums(nums) {
        int size = nums.size();
        for(int i = 1;i<size;i++){
            sums[i] = sums[i]+sums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int tmp;
        if(left == 0){tmp=0;}else{tmp=sums[left-1];}
        return sums[right]-tmp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */