#include<vector>
using namespace std;
class MaxQueue {
    int size = 0;
    int storage_left = 0;
    int storage_right = 0;
    int stk_left = 0;
    vector<int> storage;
    vector<int> stk;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(size==0){
            return -1;
        }else{
            return storage[stk[stk_left]];
        }
    }
    
    void push_back(int value) {
        storage.push_back(value);
        storage_right++;
        size = storage_right-storage_left;
        while(stk.size()>storage_left&&storage[stk.back()]<=value){
            stk.pop_back();
        }
    }
    
    int pop_front() {
        int tmp;
        if(size==0){
            tmp=-1;
        }else{
            tmp = storage[storage_left];
            storage_left++;
            while(stk[stk_left]<storage_left){
                stk_left++;
            }
            size = storage_right-storage_left;
        }
        return tmp;
    }
};
