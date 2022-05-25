#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> hp;
        for(auto& s:nums){
            hp.push(s);
            if(hp.size()>k){
                hp.pop();
            }
        }
        return hp.top();
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;

        while(true){
            int mid = left + (right-left)/2;
            swap(nums[mid],nums[right]);
            int l = left;
            int r = right;
            while(left<right){
                while(left<right&&nums[left]<nums[r]){
                    left++;
                }
                while(left<right&&nums[right]>=nums[r]){
                    right--;
                }
                swap(nums[left],nums[right]);
            }
            swap(nums[left],nums[r]);

            int whar = nums.size()-left;
            if(whar==k){
                break;
            }else if(whar>k){
                left = left+1;
                right = r;
            }else if(whar<k){
                r = left-1;
                left = l;
            }
        }
        return nums[left];
    }

    // int partition(vector<int>& nums, int k, int left, int right){
    //     int mid = left + (right-left)/2;
    //     swap(nums[mid],nums[right]);
    //     int p = right;
    //     int l = left;
    //     int r = right;
    //     while(left<right){
    //         while(left<right&&nums[left]<nums[p]){
    //             left++;
    //         }
    //         while(left<right&&nums[right]>=nums[p]){
    //             right--;
    //         }
    //         swap(nums[left],nums[right]);
    //     }
    //     swap(nums[left],nums[p]);
    //     int whar = nums.size()-left;
    //     if(whar==k){
    //         return nums[left];
    //     }else if(whar>k){
    //         return partition(nums,k,left+1,r);
    //     }else if(whar<k){
    //         return partition(nums,k,l,left-1);
    //     }
    //     return -1;
    // }
};

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution s;
    s.findKthLargest(nums,k);
}