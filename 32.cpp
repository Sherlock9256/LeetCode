#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> rec(n,0);
        int ret=0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                rec[i]=0;
            }else{
                if(i>0&&s[i-1]=='('){
                    if(i-2>=0){
                        rec[i]=rec[i-2]+2;
                    }else{
                        rec[i]=2;
                    }
                }else if(i>0&&s[i-1]==')'){
                    if(i-rec[i-1]-1>=0&&s[i-rec[i-1]-1]=='('){
                        if(i-rec[i-1]-2>=0){
                            rec[i] = rec[i-rec[i-1]-2]+rec[i-1]+2;
                        }else{
                            rec[i] = rec[i-1]+2;
                        }
                    }
                }else{
                    rec[i]=0;
                }
            }
            ret = ret>rec[i]?ret:rec[i];
        }
        return ret;
    }
};

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