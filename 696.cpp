#include<string>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int prelen=0;
        int curlen=1;
        for(int i = 1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                prelen=curlen;
                curlen=1;
            }else{
                curlen++;
            }
            if(prelen>=curlen){
                cnt++;
            }
        }
        return cnt;
    }
};