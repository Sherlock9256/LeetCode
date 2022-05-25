#include<string>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        return help(str,0,str.length());
    }
    int help(string& str,int idx,int len){
        if(idx==len)return 1;
        if(str[idx]!='1'&&str[idx]!='2'){
            cout<<3;
            return help(str,idx+1,len);
        }else{
            if(str[idx]=='1'){
                cout<<2;
                if(idx<len-1){
                    return help(str,idx+1,len)+help(str,idx+2,len);
                }else{
                    return help(str,idx+1,len);
                }
            }else{
                cout<<1;
                if(idx<len-1&&str[idx+1]<='5'&&'0'<=str[idx+1]){
                    return help(str,idx+1,len)+help(str,idx+2,len);
                }else{
                    return help(str,idx+1,len);
                }
            }
        }
    }
};