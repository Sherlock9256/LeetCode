#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int or_ = mat.size();
        int oc = mat[0].size();
        if(or_*oc!=r*c) return mat;
        vector<vector<int>> ret(r,vector<int>(c,0));
        int new_r=0;
        int new_c=0;
        for(int i = 0;i<or_;i++){
            for(int j = 0;j<oc;j++){
                ret[new_r][new_c] = mat[i][j];
                new_r = new_c==c-1?new_r+1:new_r;
                new_c = new_c==c-1?0:new_c+1;
            }
        }
        return ret;
    }
};