#include<vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size, -1);
        int idx;
        vector<int> stk;
        for(int i =0;i<2*size;i++){
            idx = i%size;
            while(!stk.empty()&&nums[stk.back()]<nums[idx]){
                ret[stk.back()] = nums[idx];
                stk.pop_back();
            }
            if(i<size){
                stk.push_back(idx);
            }
        }
        return ret;
    }
};