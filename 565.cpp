#include<vector>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int cnt=0;
        int tmp1,tmp2;
        int tmp_cnt;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=-1){
                tmp1=nums[i];
                tmp_cnt=1;
                nums[i] = -1;
                while(tmp1!=i){
                    tmp2 = nums[tmp1];
                    nums[tmp1]=-1;
                    tmp1=tmp2;
                    tmp_cnt++;
                    if(tmp_cnt==nums.size()){
                        break;
                    }
                }
                cnt = cnt<tmp_cnt?tmp_cnt:cnt;
                if(cnt>nums.size()/2){
                    break;
                }
            }
        }
        return cnt;
    }
};