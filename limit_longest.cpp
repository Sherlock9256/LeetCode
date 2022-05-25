#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
#include<climits>
using namespace std;
//1,2,3,6,5,4,7,9,6
int help(vector<int>& rec,int lim){
    int len = rec.size();
    deque<int> min_,max_;
    // min_.push_back(rec[0]);max_.push_back(rec[0]);
    int l =0,r=0;
    int ret = INT_MIN;
    while(r<len){
        //min
        while(!min_.empty()&&rec[min_.back()]>=rec[r]){
            min_.pop_back();
        }
        min_.push_back(r);
        //max
        while(!max_.empty()&&rec[max_.back()]<=rec[r]){
            max_.pop_back();
        }
        max_.push_back(r);
        r++;

        while(l<r&&!min_.empty()&&!max_.empty()&&rec[max_.front()]-rec[min_.front()]>lim){
            if(max_.front()==l)max_.pop_front();
            if(min_.front()==l)min_.pop_front();
            l++;
        }
        int tmp=r-l;
        ret = ret>tmp?ret:tmp;
        cout<<rec[max_.front()]<<" "<<rec[min_.front()]<<endl;
    }
    return ret;
}

int main(){
    vector<int> rec = {4,2,2,2,4,4,2,2};
    int limit=0;
    int ret = help(rec,limit);
    cout<<ret<<endl;
}