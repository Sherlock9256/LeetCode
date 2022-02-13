#include<stack>
using namespace std;
class CQueue {
    stack<int> out;
    stack<int> in;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(out.empty()){
            int tmp ;
            while(!in.empty()){
                tmp = in.top();
                in.pop();
                out.push(tmp);
            }
        }
        if(out.empty()){
            return -1;
        }else{
            int tmp = out.top();
            out.pop();
            return tmp;
        }
    }
};