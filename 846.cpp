#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        for(int& a:hand){
            mp[a]++;
        }
        int cnt = hand.size()/groupSize;

        for(int i = 0;i<hand.size();i++){
            if(mp[hand[i]]==0) continue;
            int tmp_cnt = mp[hand[i]];
            int tmp = 0;
            for(;tmp<groupSize&&mp[hand[i]+tmp]>=tmp_cnt;tmp++){
                mp[hand[i]+tmp]-=tmp_cnt;
            }
            if(tmp==groupSize){
                cnt-=tmp_cnt;
            }else{
                return false;
            }
        }
        
        return true;
    }
};