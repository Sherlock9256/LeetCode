#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);

        for(int i = 1;i<n+1;i++){
            ret[i] = ret[i&(i-1)] + 1;
        }
        return ret;
    }
};