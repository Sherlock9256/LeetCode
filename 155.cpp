#include<iostream>
#include<stack>
using namespace std;
class MinStack {
    stack<int> stk;
    stack<int> min_;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(min_.empty()){
            min_.push(val);
        }else{
            int tmp = min_.top();
            tmp = tmp<val?tmp:val;
            min_.push(tmp);
        }

    }
    
    void pop() {
        stk.pop();
        min_.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_.top();
    }
};