#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int l = 0;
        int r = 1;
        int cur = 0;
        for(int i =0;i<n;i++){
            cur = l+r;
            l=r;
            r=cur;
        }
        return cur;
    }
};