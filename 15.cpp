#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i <n;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int k = n-1;
            for (int j = i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                while(j<k&& (nums[j]+nums[k])>-nums[i]){
                    k--;
                }
                if(j==k){
                    break;
                }
                if(nums[j]+nums[k]==-nums[i]){
                    ret.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<int> num = {3,0,-2,-1,1,2};
    Solution s;
    s.threeSum(num);
}