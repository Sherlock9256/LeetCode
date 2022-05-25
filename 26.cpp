#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int pivot=0;
        int pre;
        for(int i = 0;i<nums.size();i++){
            if(i!=0&&nums[i]==pre){
                cnt++;
            }else{
                pre = nums[i];
                swap(nums[i],nums[pivot]);
                pivot++;
            }
        }
        int len = nums.size()-cnt;
        while(cnt){
            nums.pop_back();
            cnt--;
        }
        return len;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        int r = len;
        int cnt = 0;
        int pre_l,pre_r;
        while(l<r){
            if(l!=0&&nums[l]==pre_l){
                cnt++;
                pre_r=nums[r];
                swap(nums[l],nums[r]);
                r--;
                while(r>l&&r!=len&&nums[r]==pre_r){
                    cnt++;
                    r--;
                }
            }else{
                pre_l = nums[l];

            }
            l++;
        }
        len -= cnt;
        while(cnt){
            nums.pop_back();
            cnt--;
        }
        return len;
    }
};