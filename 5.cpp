#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int cnt = 0;
        int left,right;
        for(int i =0;i+cnt/2<s.length();i++){
            int l=i,r=i;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                int tmp = r-l+1;
                if(tmp>cnt){
                    cnt = tmp;
                    left=l;
                    right=r;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                int tmp = r-l+1;
                if(tmp>cnt){
                    cnt = tmp;
                    left=l;
                    right=r;
                }
                l--;
                r++;
            }
        }
    return s.substr(left,cnt);
    }
};