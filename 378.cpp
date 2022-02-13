#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> que;
        int j;
        for(int kk = 1;kk<=k;kk++){
            for(int i = 0;i<kk;i++){
                j = kk-i-1;
                if(0<=i&&i<m&&0<=j&&j<n){
                    que.push(matrix[i][j]);
                    if(que.size()>k){
                        que.pop();
                    }
                }
            }
        }
        return que.top();
    }
};