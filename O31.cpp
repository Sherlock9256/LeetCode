#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stk;
        int push_idx=0;
        int pop_idx=0;
        while(pop_idx<popped.size()){
            do{
                stk.push_back(pushed[push_idx]);
                push_idx++;
            }while(push_idx<pushed.size()&&stk.back()!=popped[pop_idx]);

            while(pop_idx<popped.size()&&stk.back()==popped[pop_idx]){
                stk.pop_back();
                pop_idx++;
            }
        }

        while(pop_idx<popped.size()&&popped[pop_idx]!=pu){

        }
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_map<int,int> value2idx;
        int idx = 0;
        for(auto& i:pushed){
            value2idx[i]=idx;
            idx++;
        }
        vector<bool> ok(idx,false);
        vector<bool> done(idx,false);
        int tmp;
        for(auto& i:popped){
            tmp = value2idx[i];
            if(ok[tmp]){
                done[tmp]=true;
                int iter = tmp-1;
                for(;iter>=0&&!done[tmp];iter--){}
                if(iter>=0){
                    ok[]
                }
            }else{
                return false;
            }
        }
        return true;
    }
};