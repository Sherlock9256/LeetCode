#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int b = 0;
        int cur = 0;
        int max = 0;
        while(r < s.size())
        {
            r++;
            b = l;
            while(b < r)
            {
                if (s[b] != s[r])
                {
                    b ++;
                }
                else
                {
                    cur = r - l;
                    max = cur > max ? cur : max;
                    l = b + 1;
                    break;
                }
            }
        }
        cur = r - l;
        max = cur > max ? cur : max;

        return max;
    }
};

int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "a";
    Solution s ;
    int ret = s.lengthOfLongestSubstring(s4);
    cout << ret;
    return 0;
}