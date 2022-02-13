#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ret = false;
        stack<char> stk;
        for (int i = 0;i<s.length();i++){
            if(!stk.empty()){
                if(stk.top()=='['&&s[i]==']'){
                    stk.pop();
                }else if(stk.top()=='('&&s[i]==')'){
                    stk.pop();
                }else if(stk.top()=='{'&&s[i]=='}'){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }else{
                stk.push(s[i]);
            }
        }
        if(stk.empty()){
            ret = true;
        }
        return ret;
    }
};

int main(){
    string tmp = "()[]{}";
    Solution s;
    s.isValid(tmp);
    return 0;
}