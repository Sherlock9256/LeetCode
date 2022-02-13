#include<vector>
#include<algorithm>
using namespace std;
class Solution_1 {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            return a[0]<b[0];
        });
        int size = pairs.size();
        vector<int> ret(size,1);
        int max = 0;
        for(int i = 1;i<size;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    ret[i]=ret[j]+1;
                }
            }
            max = max>ret[i]?max:ret[i];
        }
        return max;
    }
};
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            return a[1]<b[1];
        });
        
        int size = pairs.size();
        int cnt = 1;
        int end = pairs[0][1];
        for(int i = 1;i<size;i++){
            if(pairs[i][0]>end){
                end = pairs[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};