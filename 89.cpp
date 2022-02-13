#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret={0,1};
        if(n==1) return ret;
        int bit = 2;
        int tmp;
        for(int i = 2;i<=n;i++){
            tmp = ret.size()-1;
            for(int j = tmp;j>=0;j--){
                ret.push_back(ret[j]|bit);
            }
            bit<<=1;
        }
        return ret;
    }
};