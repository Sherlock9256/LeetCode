#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        return check(s,left,right,false);
    }
    bool check(string& s, int left, int right, bool del){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else if(!del){
                return check(s,left+1,right,true) || check(s,left,right-1,true);
            }else{
                return false;
            }
        }
        return true;
    }
};