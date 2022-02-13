#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](auto& a,auto&b)->bool{
            int moda = a%2;
            int modb = b%2;
            if(moda>modb){
                return true;
            }
            if(modb>moda){
                return false;
            }
            return a<b;
        });
        return nums;
    }
};
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            while(l<r&&nums[l]%2==1)l++;
            while(l<r&&nums[r]%2==0)r--;
            swap(nums[l],nums[r]);
        }
    }
};