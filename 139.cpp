#include<string>
#include<vector>
using namespace std;
class Solution_1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return search(s,wordDict,0,s.length());
    }
    bool search(string&s, vector<string>& wordDict,int idx,int len){
        if(idx==len) return true;
        int strlen;
        for(auto& str:wordDict){
            strlen = str.length();
            if(idx + strlen>len) continue;
            int i = 0;
            for(;i<strlen;i++){
                if(str[i]!=s[idx+i]) break;
            }
            if(i==strlen){
                bool ret = search(s,wordDict,idx+strlen,len);
                if(ret) return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> ret(s.length()+1,false);
        ret[0] = true;
        int len;
        for(int i =0;i<s.length();i++){
            for(auto& str:wordDict){
                len = str.length();
                if(i+1<len) continue;
                if(s.substr(i+1-len,len)==str&&ret[i+1-len]){
                    ret[i+1] = true;
                }
            }
        }
        return ret[s.length()];
    }
};