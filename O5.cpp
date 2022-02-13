#include<string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        string ret="";
        for(auto& i:s){
            if(i==' '){
                ret+="%20";
            }else{
                ret+=i;
            }
        }
        return ret;
    }
};