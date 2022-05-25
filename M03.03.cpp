#include<stack>
#include<vector>
using namespace std;
class StackOfPlates {
    vector<stack<int>> rec;
    int len = 0;
    int cap;
public:
    StackOfPlates(int ca) {
        cap = ca;
    }
    
    void push(int val) {
        if(cap==0)return;
        if(len==0||rec[len-1].size()==cap){
            rec.push_back(stack<int>());
            len++;
            rec[len-1].push(val);
        }else{
            rec[len-1].push(val);
        }
    }
    
    int pop() {
        int ret;
        if(len==0||(len==1&&rec[0].size()==0)){
            ret=-1;
        }else{
            ret = rec[len-1].top();
            rec[len-1].pop();
            if(rec[len-1].size()==0){
                rec.pop_back();
                len--;
            }
        }
        return ret;
    }
    
    int popAt(int index) {
        int ret;
        if(len-1<index){
            ret=-1;
        }else{
            ret=rec[index].top();
            rec[index].pop();
            if(rec[index].size()==0){
                rec.erase(rec.begin()+index);
                len--;
            }
        }
        return ret;
    }
};