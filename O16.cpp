#include<unordered_map>
using namespace std;
class Solution {
    unordered_map<int,double> mp;
public:
    double myPow(double x, int n) {
        mp[0]=1;
        mp[1]=x;
        mp[-1]=1/x;
        help(n);    
        return mp[n];
    }
    double help(int n){
        if(n!=1&&n!=0&&n!=-1){
            int left=n/2;int right = n-n/2;
            double tmp=1;
            if(mp.find(left)!=mp.end()){
                tmp=mp[left];
            }else{
                tmp=help(left);
            }
            if(mp.find(right)!=mp.end()){
                tmp*=mp[right];
            }else{
                tmp*=help(right);
            }
            mp[n]=tmp;
            return tmp;
        }else{
            return mp[n];
        }
    }
};