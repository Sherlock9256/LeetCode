#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return help(s,p,0,0);
    }
    bool help(string& s,string& p,int i,int j){
        if(i==s.length()&&j==p.length()){
            return true;
        }else if(i==s.length()){
            if(j<p.length()-1&&p[j+1]=='*'){
                return help(s,p,i,j+2);
            }else{
                return false;
            }
        }else if(j==p.length()){
            return false;
        }

        if(p[j]=='.'){
            if(j<p.length()-1&&p[j+1]=='*'){
                return help(s,p,i+1,j)||help(s,p,i,j+2);
            }else{
                return help(s,p,i+1,j+1);
            }
        }else{
            if(j<p.length()-1&&p[j+1]=='*'){
                if(s[i]==p[j]){
                    return help(s,p,i+1,j)||help(s,p,i,j+2);
                }else{
                    return help(s,p,i,j+2);
                }
            }else{
                if(s[i]==p[j]){
                    return help(s,p,i+1,j+1);
                }else{
                    return false;
                }
            }
        }
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        return help(s,p,0,0,s.length(),p.length());
    }
    bool help(string&s, string&p,int s_idx,int p_idx,int s_len,int p_len){
        if(s_idx==s_len&&p_idx==p_len){
            return true;
        }else if(p_idx==p_len){
            return false;
        }else if(s_idx==s_len){
            if(p_idx<p_len-1&&p[p_idx+1]=='*'){
                return help(s,p,s_idx,p_idx+2,s_len,p_len);
            }else{
                return false;
            }
        }

        //分类
        if(p_idx<p_len-1&&p[p_idx+1]=='*'){
            //下一个是*
            if(s[s_idx]!=p[p_idx]&&p[p_idx]!='.'){
                //当前不匹配,挪两个
                return help(s,p,s_idx,p_idx+2,s_len,p_len);
            }else{
                //当前匹配，挪两个或者不挪
                return help(s,p,s_idx+1,p_idx+2,s_len,p_len)||help(s,p,s_idx+1,p_idx,s_len,p_len);
            }
        }else{
            //没有下一个或下一个不是*
            if(s[s_idx]!=p[p_idx]&&p[p_idx]!='.'){
                return false;
            }else{
                return help(s,p,s_idx+1,p_idx+1,s_len,p_len);
            }
        }
    }
};