#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> p_cnt(26,0);
        vector<int> s_cnt(26,0);
        for(int i=0;i<p.length();i++){
            p_cnt[p[i]-'a'] ++;
            s_cnt[s[i]-'a'] ++;
        }
        for(int i=0;i<=s.length()-p.length();i++){
            if(i>0){
                s_cnt[s[i-1]-'a']--;
                s_cnt[s[i+p.length()-1]-'a']++;
            }
            bool in = true;
            for(int j=0;j<26;j++){
                if(p_cnt[j]!=s_cnt[j]){
                    in = false;
                    break;
                }
            }
            ret.push_back(i);
        }
        return ret;
    }
};