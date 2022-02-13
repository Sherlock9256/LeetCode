#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret=0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> cnt(n);
        // cout<<m<<" "<<n;
        for(int i = 0;i<m;i++){
            ret = max(matrix[i][0]-'0',ret);
        }        
        for(int j = 0;j<n;j++){
            ret = max(matrix[0][j]-'0',ret);
            cnt[j] = matrix[0][j]-'0';
        }
        int tmp,tmp2;
        for(int i = 1;i<m;i++){
            tmp = matrix[i][0]-'0';
            for(int j = 1;j<n;j++){
                if(matrix[i][j]>'0'){
                    tmp2 = min(min(tmp,cnt[j]),cnt[j-1]);
                    cnt[j-1] = tmp;
                    tmp = tmp2+1;
                    ret = max(tmp*tmp,ret);
                }
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return ret;
    }
};