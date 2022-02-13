#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end(),[](auto& a,auto&b){
            return a>b;
        });
        int tmp1 = nums[0]*nums[1]*nums[2];
        int tmp2 = nums[0]*nums[size-1]*nums[size-2];
        int tmp3 = nums[0]*nums[1]*nums[size-1];
        return max(tmp1,max(tmp2,tmp3));
    }
};