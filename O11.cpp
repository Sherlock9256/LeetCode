#include<vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0;
        int r = numbers.size()-1;
        int mid ;
        while(l<r){
            mid = l+(r-l)/2;
            if(numbers[mid]==numbers[r]){
                r--;
            }else if(numbers[mid]<numbers[r]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return numbers[l];
    }
};