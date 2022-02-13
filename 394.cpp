#include<string>
#include<vector>
using namespace std;
class Solution {
    char a='a';
    char z='z';
    char zero = '0';
    char nine = '9';
    char left = '[';
    char right = ']';
public:
    string decodeString(string s) {
        vector<string> strstk={""};
        vector<int> intstk={1};
        
        int idx = 0;
        int len = s.length();
        bool in = false;
        while(idx<len){
            while(idx<len&&s[idx]<=z&&a<=s[idx]){
                strstk.back()+=s[idx];
                idx++;
            }
            //数字
            if(s[idx]<=nine&&s[idx]>=zero){
                string tmp = "";
                while(idx<len&&s[idx]<=nine&&zero<=s[idx]){
                    tmp+=s[idx];
                    idx++;
                }
                intstk.push_back(de_int(tmp));
                strstk.push_back("");
                idx++; //指向左括号下一个字符
            }else if(s[idx]==right){
                //不是数字那必然是终点或者右括号。
                string tmp = strstk.back();
                for(int i = 0;i<intstk.back()-1;i++){
                    tmp += strstk.back();
                }
                strstk.pop_back();
                intstk.pop_back();
                strstk.back()+=tmp;
                idx++;
            }
        }
        return strstk.back();

    }
    int de_int(string tmp){
        int ret = 0;
        int base = 1;
        int len_ = tmp.length();
        for(int i = len_-1;i>=0;i--){
            // cout<<tmp[i]<<" ";
            ret += (tmp[i]-'0')*base;
            base*=10;
        }
        return ret;
    }
};