#include<vector>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec_min(n,vector<int>(n));
        vector<vector<int>> rec_max(n,vector<int>(n));
        for(int len=0;len<n;len++){
            for(int i = 0;i<n;i++){
                if(len==0){
                    rec_min[i][i+len]=rec_max[i][i+len]=nums[i];
                }else if(len+i<n){
                    rec_min[i][i+len]=min(rec_min[i][i+len-1],nums[i+len]);
                    rec_max[i][i+len]=max(rec_max[i][i+len-1],nums[i+len]);
                }
            }
        }
        long long ret=0;
        for(int len=0;len<n;len++){
            for(int i = 0;i<n;i++){
                if(len+i<n){
                    ret+=(long long)rec_max[i][i+len]-rec_min[i][i+len];
                }
            }
        }
        return ret;
        
    }
};