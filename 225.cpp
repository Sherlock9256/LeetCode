#include<queue>
using namespace std;

class MyStack {
    queue<int> que;

public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
        int i = que.size()-1;
        int tmp;
        while(i){
            tmp = que.front();
            que.pop();
            que.push(tmp);
            i--;
        }
    }
    
    int pop() {
        int ret = que.front();
        que.pop();
        return ret;
    }
    
    int top() { 
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};