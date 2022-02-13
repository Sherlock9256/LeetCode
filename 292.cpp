#include<vector>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        n--;
        n%=4;
        if(n==3)return false;
        return true;      
    }
};
class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> rec(n+1);
        rec[1]=rec[2]=rec[3]=true;
        for(int i = 4;i<n+1;i++){
            rec[i] = !(rec[i-1]&&rec[i-2]&&rec[i-3]);
        }
        return rec[n];
    }
};