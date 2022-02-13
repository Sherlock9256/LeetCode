#include<queue>
using namespace std;
class MedianFinder {
    int cnt = 0;
    int median = 0;
    priority_queue<int,vector<int>,greater<int>> greater;
    priority_queue<int,vector<int>,less<int>> less;



public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        cnt++;
        median = cnt/2+1;
        if(less.empty()){
            less.push(num);
        }else{
            if(num>less.top()){
                greater.push(num);
                while(less.size()<median){
                    less.push(greater.top());
                    greater.pop();
                }
            }else{
                less.push(num);
                while(less.size()>median){
                    greater.push(less.top());
                    less.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if(median%2==0){
            return 0.5*(less.top()+greater.top());
        }else{
            return less.top();
        }
    }
};