#include<vector>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ret=0;
        int end=0;
        for(int i=0;i<arr.size();i++){
            if(i>end){
                ret++;
                end=i;
            } 
            end = arr[i]>end?arr[i]:end;
        }
        ret++;
        return ret;
    }
};