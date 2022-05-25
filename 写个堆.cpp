#include<queue>
#include<iostream>
#include<vector>
using namespace std;
class Heap{
    int len=0;
    bool big;
public:
    vector<int> rec;
    Heap(bool b){big=b;}
    void push(const int& p){
        if(!len){
            rec.push_back(p);  
        }else{
            if(len==rec.size()){
                rec.push_back(p);
            }else{
                rec[len]=p;
            }
        }
        sift(len);
        len++;
    }
    int size(){
        return len;
    }
    void pop(){
        if(len){
            swap(rec[0],rec[len-1]);
            len--;
            siftdown(0);
        }else{
            cout<<"empty!"<<endl;
        }
    }
    int top(){
        if(len)return rec[0];
        cout<<"empty!"<<endl;
        return -1;
    }
    int p(int idx){return (idx-1)/2;}
    int left(int idx){return 2*idx+1;}
    int right(int idx){return 2*idx+2;}

    void sift(int idx){
        if(idx==0)return;
        if((big&&rec[idx]>rec[p(idx)])||(!big&&rec[idx]<rec[p(idx)])){
            swap(rec[idx],rec[p(idx)]);
            sift(p(idx));
        }
    }

    void siftdown(int idx){
        if(idx>=len)return;
        int l=left(idx),r=right(idx);
        if(l<len){
            int t=l;
            if(r>=len){
                t=l;
            }else if((big&&rec[l]<rec[r])||(!big&&rec[l]>rec[r])){
                t=r;
            }
            cout<<"t: "<<t<<endl;
            if((big&&rec[idx]<rec[t])||(!big&&rec[idx]>rec[t])){
                swap(rec[idx],rec[t]);
                siftdown(t);
            }
        }
    }
};