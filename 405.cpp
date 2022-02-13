#include<string>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        char chrs[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string ret="";
        unsigned int u_num = num;
        do{
            ret.insert(ret.begin(),chrs[u_num&0b1111]);
            u_num = u_num>>4;
        }while(u_num!=0);
        return ret;
    }
};