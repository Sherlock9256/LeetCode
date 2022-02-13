#include<string>
using namespace std;
class Solution_1 {
public:
    string convertToBase7(int num) {
        string ret="";
        int mod;
        int tmp = num;
        if(num<0) tmp = -tmp;
        do{
            mod = tmp%7;
            tmp/=7;
            ret.insert(ret.begin(),to_string(mod)[0]);
        }while(tmp!=0);
        if(num<0) ret.insert(ret.begin(),'-');
        return ret;
    }
};

class Solution{
public:
    string convertToBase7(int num) {
        int ret=0;
        int tmp=num>0?num:-num;
        int base=1;
        int mod;
        do{
            mod=tmp%7;
            tmp/=7;
            ret+=mod*base;
            base*=10;
        }while(tmp!=0);
        ret=num>0?ret:-ret;
        return to_string(ret);
    }
};