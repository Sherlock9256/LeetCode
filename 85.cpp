#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        vector<int> heights(n+2,0);
        vector<int> stk;
        int ret=0;
        int tmp;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[j+1]++;
                }else{
                    heights[j+1]=0;
                }
                // cout<<heights[j+1];
            }
            // cout<<endl;
            stk.clear();
            for(int j=0;j<heights.size();j++){
                if(stk.empty()){
                    stk.push_back(j);
                }else{
                    while(!stk.empty()&&heights[stk.back()]>=heights[j]){
                        tmp = stk.back();
                        stk.pop_back();
                        if(!stk.empty()){
                            tmp = heights[tmp]*(j-stk.back()-1);
                            ret=ret>tmp?ret:tmp;
                        }
                    }
                    stk.push_back(j);
                }
            }
        }
        return ret;
    }
};



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n+1,0);
        vector<int> stk;
        int ret = 0;
        for(int i = 0;i<m;i++){
            stk.clear();
            matrix[i].push_back('0');
            for(int j = 0;j<n+1;j++){
                if(matrix[i][j]=='0'){
                    heights[j] = 0;
                }else{
                    heights[j]++;
                }

                if(stk.empty()){
                    stk.push_back(j);
                }else{
                    int cur_idx,cur_len,cur_area;
                    while(!stk.empty()&&heights[stk.back()]>heights[j]){
                        cur_idx = stk.back();
                        stk.pop_back();
                        if(stk.empty()){
                            cur_len = i;
                        }else{
                            cur_len = i-stk.back()-1;
                        }
                        cur_area = cur_len * heights[cur_idx];
                        ret = ret>cur_area?ret:cur_area;
                    }
                }
            }
        }
        return ret;
    }
};
class Solution {
    int ret = 0;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> right(m+1,vector<int>(n+1,0));
        vector<vector<int>> down(m+1,vector<int>(n+1,0));
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]=='1'){
                    right[i][j] = right[i][j-1]+1; 
                }
            }
        }
        for(int j = 1;j<n;j++){
            for(int i = 1;i<m;i++){
                if(matrix[i][j]=='1'){
                    down[i][j] = down[i-1][j]+1;
                }
            }
        }
        int min_up;
        int min_left;
        int ret = 0;
        int tmp;
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                min_up = min(down[i][j],down[i][j]+1);
                min_left = min(right[i][j],right[i][j]+1);

                down[i][j] = min_up;
                right[i][j]=min_left;
                tmp = min_up*min_left;
                ret = ret>tmp?ret:tmp;
            }
        }
        return ret;
    }
};