#include<stack>
using namespace std;
class MyQueue {
    stack<int> in;
    stack<int> out;
    void in2out(){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            in2out();
        }
        int ret = out.top();
        out.pop();
        return ret;
    }
    
    int peek() {
        if(out.empty()){
            in2out();
        }
        return out.top();
    }
    
    bool empty() {
        if(out.empty()){
            in2out();
        }
        return out.empty();
    }
};