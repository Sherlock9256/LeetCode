#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        
        if(size!=m*n){
            return vector<vector<int>>();
        }
        vector<vector<int>> ret(m,vector<int>(n,0));
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ret[i][j] = original[cnt];
                cnt++;
            }
        }
        return ret;
    }
};