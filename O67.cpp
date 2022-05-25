#include<string>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int idx = 0;
        while(str[idx]==' ')idx++;
        if(str[idx]!='+'&&str[idx]!='-'&&!('0'<=str[idx]&&str[idx]<='9')){
            return 0;
        }
        bool neg=false;
        if(str[idx]=='+'){
            idx++;
        }else if(str[idx]=='-'){
            idx++;
            neg=true;
        }
        if(!('0'<=str[idx]&&str[idx]<='9')){
            return 0;
        }        
        while(str[idx]=='0'){
            idx++;
        }        
        if(!('0'<str[idx]&&str[idx]<='9')){
            return 0;
        }   
        int endidx=idx;
        while('0'<=str[endidx]&&str[endidx]<='9'){
            endidx++;
        }
        string tmp=str.substr(idx,endidx-idx);
        return decode(tmp,neg);
    }
    int decode(string& str,bool neg){
        long ret=0;
        long base=1;
        for(int i = str.length()-1;i>=0;i--){
            ret+=(str[i]-'0')*base;
            if(neg){
                if(ret>-(long)INT_MIN||base>-(long)INT_MIN){
                    return INT_MIN;
                }
            }else{
                if(ret>INT_MAX||base>INT_MAX){
                    return INT_MAX;
                }
            }
            base*=10;
        }
        return neg?-ret:ret;
    }
};