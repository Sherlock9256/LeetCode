#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<unordered_map<int,double>> rec(n);
        for(int i = 1;i<=6;i++){
            rec[0][i]=1/6.;
        }
        int tmp;
        for(int i = 1;i<n;i++){
            for(auto& p:rec[i-1]){
                for(int j = 1;j<=6;j++){
                    tmp = p.first+j;
                    rec[i][tmp]+=p.second/6;
                }
            }
        }
        vector<double> ret;
        for(int i = n*6;i>=n;i--){
            ret.push_back(rec[n-1][i]);
        }
        return ret;
    }
};
class Solution {
public:
    vector<double> dicesProbability(int n) {
        int min_=INT_MAX;
        int max_=INT_MIN;
        unordered_map<int,int>
        
    }
};