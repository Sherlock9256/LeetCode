#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &e:s){
            mp[e]++;
        }
        int ret = 0;
        bool p1 = false;
        int tmp;
        for(auto& p:mp){
            tmp = p.second%2;
            ret += p.second-tmp;
            if(!p1){
                if(tmp==1){
                    p1=true;
                }
            }
        }
        if(p1) ret++;
        return ret;
    }
};