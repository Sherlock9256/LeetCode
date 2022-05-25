#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        int tmp = columnNumber;
        int base = 26;
        int mod;
        while(tmp){
            mod = tmp%(base+1);
            ret+= 'A'+(mod-1);
            tmp/=base;
            base*=26;
        }
    }
};



















class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret="";
        int mod;
        do{
            mod = (columnNumber-1)%26;
            columnNumber = (columnNumber-1)/26;
            ret.push_back('A'+mod);
        }while(columnNumber>0);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};