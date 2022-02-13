#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int s_len = s.length(),t_len = t.length();
        while(i<s_len&&j<t_len){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i==s_len;
    }
};