#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool find = false;
        int left = 0;
        int right = num;
        int mid  ;
        long sq ;
        while(left<=right){
            mid = left + (right-left)/2;
            sq = (long) mid*mid;
            if(sq<num){
                left = mid+1;
            }else if(sq>num){
                right = mid-1;
            }else{
                find = true;
                break;
            }
        }
        return find;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        int step = 1;
        while(num>0){
            num-=step;
            step += 2;
        }
        return num==0;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0,r=num;
        int mid;
        long tmp;
        while(l<=r){
            mid = l + (r-l)/2;
            tmp = (long)(mid)*mid; 
            if(tmp==num){
                return true;
            }else if(tmp<num){
                l=mid+1;
            }else if(tmp>num){
                r=mid-1;
            }
        }
        return false;
    }
};