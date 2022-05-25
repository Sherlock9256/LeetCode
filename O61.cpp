#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int,int> mp;
        int min_=-1;
        int cnt=0;
        for(auto& a:nums){
            if(a!=0){
                mp[a]++;
                min_ = min_<a?min_:a;
            }else{
                cnt++;
            }
        }
        for(int cur=min_;cur<min_+5;cur++){
            if(mp[cur]==0){
                if(cnt==0){
                    return false;
                }else{
                    cnt--;
                }
            }
        }
        return true;
        
    }
};