#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        int base=1;
        while(n>0){
            base*=10;
            n--;
        }
        vector<int> ret;
        for(int i = 1;i<base;i++){
            ret.push_back(i);
        }
        return ret;
    }
};