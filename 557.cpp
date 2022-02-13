#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        int len = s.length();
        while(r<len){
            while(r<len&&s[r]!=' '){
                r++;
            }
            reverse(s.begin()+l,s.begin()+r);
            l = r+1;
            r=l;
        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};