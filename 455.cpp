#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1,j=s.size()-1;
        int ret = 0;
        while(i>=0&&j>=0){
            cout<<s[j]<<" "<<g[i]<<endl;
            if(s[j]>=g[i]){
                ret++;
                j--;
                i--;
            }else{
                i--;
            }
        }
        return ret;
    }
};

int main(){
    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,7,8};
    Solution sl;
    sl.findContentChildren(g,s);
}