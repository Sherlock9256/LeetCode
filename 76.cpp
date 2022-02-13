#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> tmap,smap;
       for(char p:t){
           tmap[p]++;
       }
       int left = 0;
       int right = 0;
       int left_p=-1;
       int len = INT_MAX;
       smap[s[0]]++;
       while(right<s.length()){
           while(!check(tmap,smap)&&right<s.length()){
               right++;
               smap[s[right]]++;
           }
           while(check(tmap,smap)){
               int tmp = right-left+1;
               if(tmp<len){
                   len = tmp;
                   left_p = left;
               }
               smap[s[left]]--;
               left++;
           }
       }
       if(left_p==-1){
           return "";
       }
       return s.substr(left_p,len);
    }
    bool check(unordered_map<char,int> & tmap ,unordered_map<char,int>& smap){
        for(auto& p:tmap){
            if(p.second>smap[p.first]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
