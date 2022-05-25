#include<vector>
using  namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=0;
        int pos=0;
        int pre = INT_MIN;
        int cnt=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==pre){
                cnt++;
            }else{
                pre=nums[i];
                cnt=1;
            }
            if(cnt>2){

            }else{
                nums[pos]=nums[i];
                // cout<<pos<<" "<<nums[pos]<<endl;
                pos++;

            }
        }
        return pos;
    }
};