#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0;i<nums.size();i++){
            while(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i]-1!=i){
                ret.push_back(nums[i]);
                ret.push_back(i+1);
                break;
            }
        }
        return ret;
    }
};