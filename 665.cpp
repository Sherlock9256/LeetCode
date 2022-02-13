#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int idx = 1;
        int size = nums.size();
        while(idx<size){
            if(nums[idx]<nums[idx-1]){
                if(idx-2>=0){
                    if(nums[idx]>=nums[idx-2]){
                        cnt++;
                        nums[idx-1]=nums[idx];
                    }else{
                        cnt++;
                        nums[idx] = nums[idx-1];
                    }
                }else{
                    cnt++;
                    nums[idx-1]=nums[idx];
                }
            }
            if(cnt>1){
                return false;
            }
            idx++;
        }
        return cnt<=1;
    }
};