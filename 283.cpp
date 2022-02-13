#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        int size = nums.size();
        int idx = 0;
        for(int i = 0;i<size;i++){
            if(nums[i]==0){
                cnt++;
            }else{
                nums[idx]=nums[i];
                idx++;
            }
        }
        for(int i = size-1;i>size-cnt-1;i--){
            nums[i]=0;
        }
    }
};