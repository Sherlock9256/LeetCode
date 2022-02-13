#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for(const auto& e:nums){
            sum+=e;
        }
        int mod = sum%2;
        if(mod==1) return false;
        int W = sum/2+1;
        vector<bool> cap(W,false);
        cap[0]=true;
        for(const auto& e:nums){
            for(int i = W;i>=e;i--){
                cap[i] = cap[i]||cap[i-e];
            }
        }
        return cap[W];
    }
};