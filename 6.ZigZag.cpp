#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int out;
		int len = s.length();

		int seg;

		int idx;

		string ret = "";
		out = 2 * numRows - 2;
		seg = len / out + ((len%out == 0) ? 0 : 1);

		for (int linecnt = 0; linecnt < numRows; linecnt++) {
			if (linecnt == 0 || linecnt == numRows - 1) {
				for (int segcnt = 0; segcnt <seg; segcnt++) {
					idx = linecnt + segcnt * out;
					if (idx < len) {
						ret += s[idx];
					}
				}
			}
			else {
				for (int segcnt = 0; segcnt <seg; segcnt++) {
					idx = linecnt + segcnt * out;
					if(idx < len)
						ret += s[idx];
					idx = segcnt * out + (2 * (numRows - 1) - linecnt);
					if(idx < len)
						ret += s[idx];
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	string str = "A";
	int numRows = 1;
	string ret = s.convert(str, numRows);
	return 0;
}