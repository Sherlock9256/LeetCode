#include<vector>
using namespace std;
class Solution {
public:
    int Wrong_num(int s) {
        vector<int> cnt(s+1,0);
        for(int i = 1;i<s+1;i++){
            for(int j = i-1;j>i/2;j--){
                cnt[i] += cnt[j] * cnt[i-j];
                if(j!=i-j){
                    cnt[i] += cnt[j] * cnt[i-j];
                }
            }
            cnt[i]+=i-1;
        }
        return cnt[s];
    }
};