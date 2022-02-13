#include<vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        bool climb = true;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>=nums[left]){
                if(climb){
                    left = i;
                }
            }else{
                climb = false;
                while(left!=0&&nums[i]<nums[left]){
                    left--;
                }
                if(nums[i]>=nums[left]){
                    left++;
                }else{
                    break;//0
                }
                // break;
            }
        }
        if(left==right){
            return 0;
        }
        climb = true;
        for(int i = right-1;i>left;i--){
            if(nums[i]<=nums[right]){
                if(climb){
                    right=i;
                }
            }else{
                climb = false;
                while(right!=nums.size()-1&&nums[i]>nums[right]){
                    right++;
                }
                if(nums[i]<=nums[right]){
                    right--;
                }else{
                    break;
                }
            }
        }
        cout<<left<<" "<<right<<endl;
        return right-left+1;
    }
};