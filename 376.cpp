#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cur = nums[0];
        int pre = 0;
        int cnt = 1;
        int size = nums.size();
        if(size==1) return 1;
        pre=nums[1]-nums[0];
        if(pre==0){
            cnt=1;
        }else{
            cnt++;
            cur = nums[1];
        }
        int tmp;
        
        for(int i = 2;i<size;i++){
            tmp = nums[i]-cur;
            if(tmp!=0){
                if(pre==0){
                    cnt++;
                    pre=tmp;
                    cur=nums[i];
                }else{
                    if(tmp*pre<0){
                        cnt++;
                        pre=tmp;
                        cur=nums[i];
                    }else{
                        pre=tmp;
                        cur=nums[i];
                    }
                }
            }else{
                cur=nums[i];
            }
        }
        return cnt;
    }
};