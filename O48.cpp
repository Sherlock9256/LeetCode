#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> chr2cnt;
        int l=0;
        int r=0;
        int ret = 0;
        int len = s.length();
        int tmp;
        while(r<len){
            while(chr2cnt[s[r]]==0){
                tmp = r-l;
                ret = tmp>ret?tmp:ret;
                r++;
                chr2cnt[s[r]]++;
            }
        }
    }
};