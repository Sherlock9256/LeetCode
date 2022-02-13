#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
	int reverse(int x){
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

	
	int MYreverse(int x) {
		if (x == -pow(2, 31))
			return 0;

		double ret = 0;

		int mod, div = x;

		int pos = -1;
		do {
			div /= 10;
			pos++;
		} while (div != 0);
		div = x;
		do {
			mod = div % 10;
			div /= 10;
			ret += mod * pow(10, pos);
			if (ret > pow(2, 31) - 1 || ret < -pow(2, 31)) {
				return 0;
			}
			pos--;
		} while (pos >= 0);
		return ret;
	}
};

int main() {
	Solution s;
	int q = -pow(2,31);
	int ret = s.reverse(q);
	cout << ret;
	return 0;
}