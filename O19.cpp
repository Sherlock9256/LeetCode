#include<string>
using namespace std;
class Solution {
    int s_len;
    int p_len;
public:
    bool isMatch(string s, string p) {
        s_len = s.length();
        p_len = p.length();
        return help(s,p,0,0);
    }

    bool help(string& s,string& p,int s_idx,int p_idx){
        if(s_idx==s_len){
            if(p_idx==p_len){
                return true;
            }else if(p_idx<p_len-1&&p[p_idx+1]=='*'){
                return help(s,p,s_idx,p_idx+2);
            }else{
                return false;
            }
        }
        if(p_idx==p_len)return false;

        if(p_idx<p_len-1&&p[p_idx+1]=='*'){
            if(s[s_idx]!=p[p_idx]&&p[p_idx]!='.'){
                return help(s,p,s_idx,p_idx+2);
            }else{
                return help(s,p,s_idx+1,p_idx)||help(s,p,s_idx,p_idx+2);
            }
        }else{
            if(s[s_idx]!=p[p_idx]&&p[p_idx]!='.')return false;
            return help(s,p,s_idx+1,p_idx+1);
        }
    }
};