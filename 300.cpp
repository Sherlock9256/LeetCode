#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> rec(nums.size(),1);
        int ret = 0;
        for(int i = 0;i<nums.size();i++){
            int tmp = 0;
            for(int j= 0;j<i;j++){
                if(nums[i]>nums[j]){
                    tmp = tmp>rec[j]?tmp:rec[j];
                }
            }
            rec[i]=tmp+1;
            ret=ret>rec[i]?ret:rec[i];
        }
        return ret;
    }
};































class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size);
        int tmp;
        int top = 0;
        for(int i = 0;i<size;i++){
            tmp = 0;
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    tmp = max(tmp,ret[j]);
                }
            }
            ret[i] = tmp+1;
            top = top>ret[i]?top:ret[i];
        }
        return top;

    }
};