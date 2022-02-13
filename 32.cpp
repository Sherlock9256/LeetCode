#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> intstk;
        vector<char> charstk;
        for(char chr:s){
            if(chr=='('){
                intstk.push_back(1);
                charstk.push_back('(');
            }else{
                if(charstk.empty()||charstk.back()!='('){
                    //ignore
                }else{
                    charstk.pop_back();
                    int ret = 0;
                    while(intstk.back()!=1){
                        ret += intstk.back();
                        intstk.pop_back();
                    }
                    intstk.back()+=ret+1;
                    ret = intstk.back();
                    intstk.pop_back();
                    while(!intstk.empty()&&intstk.back()!=1){
                        ret+=intstk.back();
                        intstk.pop_back();
                    }
                    intstk.push_back(ret);
                }
            }
        }
        int ret = 0;
        for(int i :intstk){
            if(i!=1){
                ret = ret>i?ret:i;
            }
        }
        return ret;
    }
};