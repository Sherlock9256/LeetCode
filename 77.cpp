#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> stk;
        search(ret,stk,n,1);
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& stk,int n,int idx){
        if(stk.size()==n){
            ret.push_back(stk);
        }else{
            for(int i = idx;i<=n;i++){
                stk.push_back(i);
                search(ret,stk,n,i+1);
                stk.pop_back();
            }
        }
    }
};