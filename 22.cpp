#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
    vector<string> ret;
public:
    vector<string> generateParenthesis(int n) {
        string tmp;
        help(tmp,0,0,n);
        return ret;
    }
    void help(string& tmp,int l,int r,int n){
        if(r==n){
            ret.push_back(tmp);
            return;
        }
        if(l>r){
            tmp.push_back(')');
            help(tmp,l,r+1,n);
            tmp.pop_back();
        }
        if(l<n){
            tmp.push_back('(');
            help(tmp,l+1,r,n);
            tmp.pop_back();
        }
    }
};


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