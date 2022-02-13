#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int size = nums.size();
        int first_neg = -1;
        int neg_cnt = 0;
        int max_ = INT_MIN;
        for(int i = 0;i<size;i++){
            if(nums[i]>0){
                if(i-1>=0&&nums[i-1]>0){
                    nums[i] = nums[i]*nums[i-1];
                }else if(i-1>=0&&nums[i-1]<=0){
                    nums[i]=nums[i];
                }else{
                    nums[i]=nums[i];
                }
            }else if(nums[i]<0){
                if(first_neg==-1){
                    nums[i]=nums[i];
                    first_neg = i;
                }else if(first_neg!=-1){
                    nums[i] = nums[i]*nums[first_neg];
                    if(first_neg-1>=0){
                        nums[i]*=nums[first_neg-1];
                    }
                    if(i-1>=0&&nums[i-1]>0){
                        nums[i]*=nums[i-1];
                    }
                    first_neg = -1;
                }
            }else{
                first_neg = -1;
            }
            max_ = max_>nums[i]?max_:nums[i];
        }
        return max_;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int size = nums.size();
        int ret = nums[0];
        int max_ = nums[0];
        int min_ = nums[0];
        int tmpmin,tmpmax;
        for(int i = 1;i<size;i++){
            tmpmax = max(max(max_*nums[i],min_*nums[i]),nums[i]);
            tmpmin = min(min(max_*nums[i],min_*nums[i]),nums[i]);
            max_ = tmpmax;
            min_ = tmpmin;
            ret = max(ret,max_);
        }
        return ret;
    }
};