#include<string>
#include<algorithm>
using namespace std;
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