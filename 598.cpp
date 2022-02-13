#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_l=m,min_r=n;
        for(int cnt = 0;cnt<ops.size();cnt++){
            if(min_l>ops[cnt][0]){
                min_l=ops[cnt][0];
            }
            if(min_r>ops[cnt][1]){
                min_r=ops[cnt][1];
            }
        }
        return min_l*min_r;
    }
};
