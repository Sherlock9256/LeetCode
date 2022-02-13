#include<iostream>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        bool found = false;

        int right = sqrt(c);
        int left = 0;
        int mid = sqrt(c/2);
        int sum ;
        while(left<=mid&&right>=mid){
            sum = left*left + right*right;
            if(sum > c){
                right--;
            }else if(sum <c){
                left++;
            }else{
                found = true;
                break;
            }
        }

        return found;
    }
};