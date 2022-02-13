#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ret="";
        int len = s.length();
        reverse(s.begin(),s.end());
        int l=0,r=0;
        while(r<=len){
            if(s[r]==' '||r==len){
                if(l!=r){
                    reverse(s.begin()+l,s.begin()+r);
                    ret+=" "+s.substr(l,r-l);
                }
                l=r+1;
                // cout<<s<<endl;
                // cout<<s.substr(l,r-l)<<endl;
            }
            r++;
        }
        if(ret.length()){
            return ret.substr(1);
        }else{
            return ret;
        }
    }
};