#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		int ml = 0;
		int max = 0;
		int cur = 0;
		int next = 0;
		int len = 0;
		int bw;
		int fw;

		while (next < s.length()) {

			cur = next;
			next++;

			bw = fw = cur;

			while (bw >= 0 && fw < s.length() && s[bw] == s[fw]) {
				bw--;
				fw++;
			}

			len = fw - bw - 1;  //调整距离
			if (len > max) {
				max = len;
				ml = bw + 1;
			}
            
			if (fw == s.length()) {
				break;
			}

            if (s[next] == s[cur]) {
				bw = cur;
				fw = next;
                while (bw >= 0 && fw < s.length() && s[bw] == s[fw]) {
                    bw--;
                    fw++;
                }

                len = fw - bw - 1;  //调整距离
                if (len > max) {
                    max = len;
                    ml = bw + 1;
                }

                if (fw == s.length()) {
                    break;
                }
			}

		}
		return s.substr(ml, max);
	}
};

int main() {
	Solution s;
	string str = "";
	string ret = s.longestPalindrome(str);
	cout << ret;
	return 0;
}