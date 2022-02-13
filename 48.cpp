#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        help(matrix,0,matrix.size()-1);
    }
    void help(vector<vector<int>>& matrix,int a,int b){
        if(a>=b) return;
        int len = b-a;//=
        vector<int> tmp;
        for(int i = 0;i<len;i++){
            // cout<<(matrix[a][a+i]);
            tmp.push_back(matrix[a][a+i]);
            // cout<<tmp[i]<<endl;
        }
        //right
        for(int i = 0;i<len;i++){
            matrix[a+i][a+len] ^= tmp[i];
            tmp[i] ^= matrix[a+i][a+len];
            matrix[a+i][a+len] ^= tmp[i];
            // cout<<matrix[a+i][a+len]<<" "<<tmp[i]<<endl;
        }
        // down
        for(int i = len-1;i>=0;i--){
            matrix[a+len][a+i+1] ^= tmp[len-i-1];
            tmp[len-i-1] ^= matrix[a+len][a+i+1];
            matrix[a+len][a+i+1] ^= tmp[len-i-1];
        }
        // for(int i = 0;i<len;i++){
        //     cout<<tmp[i]<<endl;
        // }
        //left
        for(int i = len-1;i>=0;i--){
            matrix[a+i+1][a] ^= tmp[len-i-1];
            tmp[len-i-1] ^= matrix[a+i+1][a];
            matrix[a+i+1][a] ^= tmp[len-i-1];
        }
        //up   
        for(int i = 0;i<len;i++){
            matrix[a][a+i] ^= tmp[i];
            tmp[i] ^= matrix[a][a+i];
            matrix[a][a+i] ^= tmp[i];
        }
        help(matrix,a+1,b-1);
    }
};