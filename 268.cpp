#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = (n)*(n+1)/2;
        int sum = 0;
        for (int i =0;i<n;i++){
            sum += nums[i];
        }
        return s-sum;
    }
};

int main(){
    Solution s;
    vector<int> ret = {3,0,1};
    cout<<s.missingNumber(ret)<<endl;
    return 0;
}