#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0,j=numbers.size()-1;
        int sum ;
        vector<int> ret;
        while(i<j){
            sum = numbers[i]+numbers[j];
            if(sum>target){
                j--;
            }else if(sum>target){
                i++;
            }else{
                ret.push_back((i+1,j+1));
                return ret;
            }
        }
    }
};