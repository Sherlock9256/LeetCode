#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a=0;
        int b=0;
        do{
            a = nums[a];
            b = nums[nums[b]];
        }while(a!=b);

        b=0;
        while(a!=b){
            a = nums[a];
            b = nums[b];
        }
        return a;
    }
};



























class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast = 0;
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};