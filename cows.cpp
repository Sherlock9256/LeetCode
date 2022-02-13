#include<vector>
using namespace std;
class Solution {
public:
    int n_cows(int n) {
        vector<int> cows(n+3,0);
        cows[0]=cows[1]=cows[2]=1;
        for(int i = 3;i<n+3;i++){
            cows[i]=cows[i-1]+cows[i-3];
        }
        return cows[n+3-1];
    }
};