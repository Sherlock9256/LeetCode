#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> b(a.size());
        vector<int> c(a.size());
        b[0]=1;
        c[a.size()-1]=1;
        for(int i = 0;i<a.size()-1;i++){
            b[i+1] = a[i]*b[i];
        }
        for(int i = a.size()-1;i>0;i--){
            c[i-1] = a[i]*c[i];
        }
        for(int i = 0;i<a.size();i++){
            b[i]*=c[i];
        }
        return b;
    }
};