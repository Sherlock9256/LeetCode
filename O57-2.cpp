#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        int l=1,r=1;
        int sum=0;
        while(r<target){
            while(sum<target&&r<target) {
                sum += r;
                r++;
            }
            while(sum>target&&l<r){
                sum-=l;
                l++;
            }
            if(sum==target){
                vector<int> tmp;
                for(int i = l;i<=r;i++){
                    tmp.push_back(i);
                }
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};