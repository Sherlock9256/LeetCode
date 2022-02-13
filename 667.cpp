#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret(n);
        ret[0]=1;
        for(int i = 1,intv=k;i<k+1;i++,intv--){
            ret[i] = i%2==1?ret[i-1]+intv:ret[i-1]-intv;
        }
        for(int i = k+1;i<n;i++){
            ret[i]=i+1;
        }
        return ret;
    }
};