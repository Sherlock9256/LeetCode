#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(i==0){
                nums[i] = i+nums[i];
            }else{
                if(nums[i-1]>=i){
                    nums[i] = max(nums[i-1],i+nums[i]);
                }
            }
            cout<<nums[i]<<endl;
        }
        return nums[nums.size()-1] >= nums.size()-1;
    }
};

int main(){
    Solution s;
    vector<int> p = {3,2,1,0,4};
    s.canJump(p);

}