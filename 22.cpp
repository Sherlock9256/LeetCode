#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str="(";
        gen(ret,str,n-1,n);
        return ret;
    }
    void gen(vector<string>& ret,string str,int left,int right){
        if(right==0){
            ret.push_back(str);
            return;
        }else{
            if(left<right){
                gen(ret,str+')',left,right-1);
            }
            if(left>0){
                gen(ret,str+'(',left-1,right);
            }
        }
    }
};

int main(){


    return 0;
}