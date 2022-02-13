#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0];
        int first[2];first[0]=nums[0];first[1]=max(nums[0],nums[1]);
        if(size==2) return first[1];
        int second[2];second[0]=0;second[1]=nums[1];
        int tmp;
        for(int i = 2;i<size;i++){
            if(i<size-1){
                tmp = max(nums[i]+first[0],first[1]);
                first[0] = first[1];
                first[1] = tmp;
            }
            tmp = max(nums[i]+second[0],second[1]);
            second[0]=second[1];
            second[1]=tmp;
        }
        return max(first[1],second[1]);
    }
};