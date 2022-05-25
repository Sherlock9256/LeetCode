// 给定一个无序的整数序列，找到第一个缺失的正整数。
// 要求时间复杂度为  O(n)，空间复杂度为 O(1)
// 例如：输入[3,6,4,-1,1]，返回2 

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int help(vector<int>& rec){
    int size = rec.size();
    for(int i =0;i<size;i++){
        while(rec[i]>0&&rec[i]<=size&&rec[i]!=i+1){
            swap(rec[i],rec[rec[i]-1]);
        }
    }
    for(int i=0;i<size;i++){
        if(rec[i]!=i+1){
            return i+1;
        }
    }
    return size+1;

}

int main(){
    while(1){
        int size;
        cin>>size;
        vector<int> rec(size);
        for(int i=0;i<size;i++){
            cin>>rec[i];
        }
        int ret = help(rec);
        cout<<"miss:\t"<<ret<<endl;
        cout<<"-------------------"<<endl;
    }
}