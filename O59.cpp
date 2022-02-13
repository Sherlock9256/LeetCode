#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        vector<int> stk;
        for(int i = 0;i<k-1;i++){
            while(!stk.empty()&&nums[stk.back()]<=nums[i]){
                stk.pop_back();
            }
            stk.push_back(i);
        }
        // cout<<1;
        for(int i = k-1;i<nums.size();i++){
            if(!stk.empty()&&stk[0]+k<=i){
                int left = 0;
                while(left<stk.size()&&stk[left]+k<=i){
                    left++;
                }
                vector<int> newstk;
                for(int tmp=left;tmp<stk.size();tmp++){
                    newstk.push_back(stk[tmp]);
                }
                stk = newstk;
            }
            while(!stk.empty()&&nums[stk.back()]<=nums[i]){
                stk.pop_back();
            }
            stk.push_back(i);
            // cout<<i<<endl;
            ret.push_back(nums[stk[0]]);
        }
        return ret;
    }
};