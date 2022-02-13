#include<deque>
#include<queue>
using namespace std;
class MaxQueue {
    deque<int> max_;
    queue<int> data;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return max_.front();
    }
    
    void push_back(int value) {
        data.push(value);
        while(!max_.empty()&&max_.back()>value){
            max_.pop_back();
        }
        max_.push_back(value);
    }
    
    int pop_front() {
        int tmp = data.front();
        data.pop();
        if(max_.front()==tmp){
            max_.pop_front();
        }
    }
};