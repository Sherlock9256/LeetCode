#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
    }
};





















class Solution_1 {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        int k = len/2;
        partition(nums,k,0,len-1);
        int ret = 0;
        for(int i =0;i<len;i++){
            ret+= abs(nums[i]-nums[k]);
        }
        return ret;
    }
    void partition(vector<int>& nums,int target,int left,int right){
        if(left==right) return;
        int mid = left + (right-left)/2;
        swap(nums[mid],nums[right]);
        int l = left,r=right-1;
        while(true){
            while(nums[l]<nums[right]&&l<right) l++;
            while(nums[r]>=nums[right]&&r>left) r--;
            if(l>=r) break;
            swap(nums[l],nums[r]);
        }
        swap(nums[l],nums[right]);
        if(l<target){
            partition(nums,target,l+1,right);
        }else if(l>target){
            partition(nums,target,left,l-1);
        }
    }
};


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int k = len/2;
        int ret = 0;
        for(int i =0;i<len;i++){
            ret+= abs(nums[i]-nums[k]);
        }
        return ret;

    }
};