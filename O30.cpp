#include<stack>
using namespace std;
class MinStack {
    stack<int> data;
    stack<int> min_;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if(min_.empty()){
            min_.push(x);
        }else if(min_.top()>=x){
            min_.push(x);
        }
    }
    
    void pop() {
        if(!data.empty()){
            int x = data.top();
            data.pop();
            if(min_.top()==x){
                min_.pop();
            }
        }
    }
    
    int top() {
        // cout<<data.top()<<endl;
        return data.top();
    }
    
    int min() {
        // cout<<min_.top()<<endl;
        return min_.top();
    }
};