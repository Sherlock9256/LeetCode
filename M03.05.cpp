#include<stack>
using namespace std;
class SortedStack {
    stack<int> stk;
public:
    SortedStack() {

    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(val);
        }else{
            stack<int> tmp;
            while(!stk.empty()&&stk.top()<val){
                tmp.push(stk.top());
                stk.pop();
            }
            stk.push(val);
            while(!tmp.empty()){
                stk.push(tmp.top());
                tmp.pop();
            }
        }
    }
    
    void pop() {
        if(!stk.empty()) stk.pop();
    }
    
    int peek() {
        if(stk.empty()){
            return -1;
        }else{
            return stk.top();
        }
    }
    
    bool isEmpty() {
        return stk.empty();
    }
};