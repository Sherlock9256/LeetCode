#include<string>
using namespace std;
class Solution {
    int cnt=0;
public:
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++){
            extend(s,i,i);
            extend(s,i,i+1);
        }
        return cnt;
    }
    void extend(string& s,int l,int r){
        while(l>=0&&r<=s.length()&&s[l]==s[r]){
            l--;
            r++;
            cnt++;
        }
    }
};