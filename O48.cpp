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
            while(r<len&&chr2cnt[s[r]]==0){
                tmp = r-l+1;
                ret = tmp>ret?tmp:ret;
                chr2cnt[s[r]]++;
                r++;
            }
            while(r<len&&l<=r&&chr2cnt[s[r]]==1){
                chr2cnt[s[l]]--;
                l++;
            }
        }
        return ret;
    }
};