#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        priority_queue<int> que;
        int cnt = (nums.size()+1)/2;
        for(auto num:nums){
            que.push(num);
            cnt--;
            if(cnt<0){
                que.pop();
            }
        }
        return que.top();
    }
};

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int k = (nums.size()+1)/2;
        partition(nums,0,nums.size()-1,k);
        return nums[k];
    }
    void partition(vector<int>& nums,int left,int right,int k){
        if(left==right) return;
        int target = nums[right];
        int l = left;
        for(int r=left;r<=right;r++){
            if(nums[r]<target){
                swap(nums[l],nums[r]);
                l++;
            }
        }
        swap(nums[l],nums[right]);
        if(l<k){
            partition(nums,l+1,right,k);
        }else if(l>k){
            partition(nums,left,l-1,k);
        }
    }
};

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int m;
        int cnt=0;
        for(auto& num:nums){
            m= cnt==0?num:m;
            cnt = m==num?cnt+1:cnt-1;
        }
        return m;
   }
};