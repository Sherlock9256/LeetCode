#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> leftcnt;
        unordered_map<int,int> endcnt;
        for(auto& a:nums){
            leftcnt[a]++;
        }
        for(auto& a:nums){
            if(endcnt[a-1]>0){
                endcnt[a-1]--;
                endcnt[a]++;
                leftcnt[a]--;
            }else{
                if(leftcnt[a+1]>0&&leftcnt[a+2]>0){
                    leftcnt[a+1]--;
                    leftcnt[a+2]--;
                    leftcnt[a]--;
                    endcnt[a+2]++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};