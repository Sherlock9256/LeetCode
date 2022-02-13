class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(i==0){
                nums[i] = i+nums[i];
            }else{
                if(nums[i-1]>=i){
                    nums[i] = max(nums[i-1],i+nums[i]);
                }else{
                    nums[i] = -1;
                }
            }
            cout<<nums[nums.size()-1]<<endl;
        }
        cout<<nums[nums.size()-1]<<endl;
        cout<<nums.size()-1<<endl;
        int p = nums[nums.size()-1];
        int q = nums.size()-1;
        return p>=q;
    }
};