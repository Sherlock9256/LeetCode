#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return n;
        int sgn = nums[1]-nums[0];
        int top = nums[1];
        int cur;
        int tmp;
        int ret = sgn==0?1:2;
        for(int i = 2;i<n;i++){
            cur=nums[i];
            tmp = sgn*(cur-top);
            if(tmp>0){
                top = cur;
            }else if(tmp<0){
                sgn = cur-top;
                top = cur;
                ret++;
            }else if((cur-top)!=0){
                sgn = cur-top;
                top = cur;
                ret++;
            }
        }
        return ret;
    }
};



























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