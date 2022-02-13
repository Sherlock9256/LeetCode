#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> cur;
        search(ret,cur,n,k,1,0);
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,int n,int k,int idx,int sum){
        for(int i = idx;i<10;i++){
            cout<<cur.size()<<" ";
            sum += i;
            if(sum==n&&cur.size()==k-1){
                cur.push_back(i);
                ret.push_back(cur);
                cur.pop_back();
                break;
            }else if(sum<n&&cur.size()<k-1){
                cur.push_back(i);
                search(ret,cur,n,k,i+1,sum);
                cur.pop_back();
                sum-=i;
            }else if(sum<n&&cur.size()==k-1){
                sum-=i;
            }else{
                break;
            }
        }
    }
};

int main(){
    Solution s;
    s.combinationSum3(3,7);
}