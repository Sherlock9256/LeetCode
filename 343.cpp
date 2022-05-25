#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<int,int> mp;
public:
    int integerBreak(int n) {
        return help(n,n);
    }
    int help(int n,int sum){
        if(mp.count(n))return mp[n];
        int ret = 1;
        int tmp = 1;
        int left,right;
        for(int i = 1;i<=n/2;i++){
            left = help(i,sum);
            right= help(n-i,sum);
            tmp = left*right;
            ret = max(ret,tmp);
        }
        if(n!=sum){
            ret = ret>n?ret:n;
        }
        mp[n]=ret;
        return ret;
    }
};
















class Solution {
public:
    int integerBreak(int n) {
        vector<int> ret(n+1);
        ret[1]=1;
        int max = 0;
        int tmp;
        for(int i = 2;i<n+1;i++){
            max = 0;
            for(int j = 1;j<i;j++){
                tmp = ret[j]*(ret[i-j]);
                if(tmp>max){
                    max = tmp;
                }
                tmp = ret[j]*(i-j);
                if(tmp>max){
                    max = tmp;
                }
                tmp = j*(ret[i-j]);
                if(tmp>max){
                    max = tmp;
                }
                tmp = j*(i-j); 
                if(tmp>max){
                    max = tmp;
                }              
            }
            ret[i]=max;
        }
        return ret[n];
    }
};
