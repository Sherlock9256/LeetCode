#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> stk;
        int ret = 0;
        for(int i = 0;i<heights.size();i++){
            if(stk.empty()){
                stk.push_back(i);
            }else{
                int cur_idx;
                int cur_len;
                int cur_area;
                while(!stk.empty()&&heights[stk.back()]>heights[i]){
                    cur_idx = stk.back();
                    stk.pop_back();
                    if(stk.empty()){
                        cur_len = i;
                    }else{
                        cur_len = i-stk.back()-1;
                    }
                    cur_area = cur_len*heights[cur_idx];
                    ret = ret>cur_area?ret:cur_area;
                }
                stk.push_back(i);
            }
        }
        return ret;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> rec(len,0);
        vector<int> stk;
        stk.push_back(0);
        rec[0] = 1;
        for(int idx = 1;idx<len;idx++){
            int tmp;
            while(!stk.empty()&&stk.back()>heights[idx]){
                tmp = stk.back();
                stk.pop_back();
            }
            if(stk.empty()){
                rec[idx] = idx+1;
            }else{
                rec[idx] = idx-stk.back();
            }
            stk.push_back(idx);
        }
        int end = stk.back();
        for(int idx = 0;idx<len;idx++){
            rec[stk[idx]] += end-stk[idx];
        }
        int ret = 0;
        int tmp;
        for(int i = 0;i<len;i++){
            tmp = heights[i]*rec[i];
            ret = ret>tmp?ret:tmp;
        }
        return ret;
    }
};