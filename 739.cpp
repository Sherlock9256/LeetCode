#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ret(size,0);
        vector<int> stk;
        for(int i=0;i<size;i++){
            if(stk.empty()){
                stk.push_back(i);
            }else{
                while(!stk.empty()&&temperatures[stk.back()]<temperatures[i]){
                    
                    ret[stk.back()] = i-stk.back();
                    stk.pop_back();
                }
                stk.push_back(i);
            }
        }
        return ret;
    }
};