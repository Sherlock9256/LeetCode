#include<string>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        unsigned int base = 1;
        unsigned int ret=0;
        int len = columnTitle.length();
        for(int i = len-1;i>=0;i--){
            ret += base*(columnTitle[i]-'A'+1);
            base*=26;
        }
        return ret;
    }
};


















class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        unsigned int ret=0;
        unsigned int base = 1;
        for(int i = len-1;i>=0;i--){
            ret+= (unsigned int)(columnTitle[i]-'A'+1)*base;
            base*=26;
        }
        return ret;
    }
};