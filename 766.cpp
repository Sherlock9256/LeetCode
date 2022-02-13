#include<vector>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    int k = 1;
                    int pre = matrix[i][j];
                    while(i+k<m&&j+k<n){
                        if(matrix[i+k][j+k]!=pre){
                            return false;
                        }
                        k++;
                    }
                }
            }
        }
        return true;
    }
};