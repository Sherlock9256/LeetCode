#include<algorithm>
using namespace std;
class Solution_1 {
public:
    int trailingZeroes(int n) {
        int two=0,five=0;
        int tmp_i;
        for(int i=n;i>0;i--){
            tmp_i=i;
            while(tmp_i%2==0){
                tmp_i/=2;
                two++;
            }
            while(tmp_i%5==0){
                tmp_i/=5;
                five++;
            }
        }
        return min(two,five);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5;
        int cnt = 0;
        while(n>0){
            cnt += n/base;
            n/=base;
            base*=5;
        }
        return cnt;
    }
};