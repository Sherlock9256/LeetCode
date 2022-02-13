#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        //decode
        vector<int> ret;
        cout<<expression.length();
        for(int idx = 0;idx<expression.length();idx++){
            if(expression[idx]=='+'||expression[idx]=='-'||expression[idx]=='*'){
                vector<int> left = diffWaysToCompute(expression.substr(0,idx));
                vector<int> right = diffWaysToCompute(expression.substr(idx+1));
                for(auto& l:left){
                    for(auto& r:right){
                        if(expression[idx]=='+'){
                            ret.push_back(l+r);
                        }
                        if(expression[idx]=='-'){
                            ret.push_back(l-r);
                        }
                        if(expression[idx]=='*'){
                            ret.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(ret.size()==0){
            ret.push_back(stoi(expression));
        }
        return ret;
    }
};

int main(){
    string exp = "2-1-1";
    Solution s;
    s.diffWaysToCompute(exp);
}