#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        bool yes = false;
        int ret = 0;
        for(int i = s.length()-1;i>=0;i--){
            if(yes){
                if(mp[s[i]]==mp[s[i+1]]/5||mp[s[i]]==mp[s[i+1]]/10){
                    ret-=mp[s[i]];
                    yes=false;
                }else{
                    ret+=mp[s[i]];
                }
            }else{
                ret+=mp[s[i]];
                yes=true;
            }
        }
        return ret;
    }
};