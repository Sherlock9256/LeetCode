#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    unordered_map<int,unordered_map<int,bool>> mp;
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur ;
        help(s,cur,0);
        return ret;
    }
    void help(string& s,vector<string>& cur,int idx){
        if(idx==s.length()){
            ret.push_back(cur);
            return;
        }
        for(int i = idx;i<s.length();i++){
            if(check(s,idx,i)){
                cur.push_back(s.substr(idx,i-idx+1));
                help(s,cur,i+1);
                cur.pop_back();
            }
        }
    }
    bool check(string& s,int i ,int j){
        if(i>=j)return true;
        if(mp.count(i)&&mp[i].count(j)){
            return mp[i][j];
        }else{
            bool tmp = check(s,i+1,j-1);
            tmp = tmp&&s[i]==s[j];
            mp[i][j]=tmp;
            return tmp;
        }
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> cur;
        int len = s.length();
        search(ret,cur,s,0,len);
        return ret;
    }
    void search(vector<vector<string>>& ret,vector<string>& cur,string& s,int idx,int len){
        if(idx==len){
            ret.push_back(cur);
        }else{
            string tmp ="";
            int tmp_len = 0;
            bool same = true;
            bool yes = true;
            for(int i = idx;i<len;i++){
                tmp.push_back(s[i]);
                tmp_len++;
                if(tmp_len==1){
                    cur.push_back(tmp);
                    search(ret,cur,s,i+1,len);
                    cur.pop_back();
                }else if(yes&&same&&s[i]==tmp[0]){
                    cur.push_back(tmp);
                    search(ret,cur,s,i+1,len);
                    cur.pop_back();
                }else if(yes&&same&&s[i]!=tmp[0]){
                    yes=false;
                    same=false;
                }else{
                    yes = check(tmp,tmp_len);
                    if(yes){
                        cur.push_back(tmp);
                        search(ret,cur,s,i+1,len);
                        cur.pop_back();
                    }
                }
            }
        }
    }
    bool check(string&tmp,int len){
        for(int i = 0;i<len/2;i++){
            if(tmp[i]!=tmp[len-1-i]){
                return false;
            }
        }
        return true;
    }
};