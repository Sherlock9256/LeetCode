#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int step[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string simp[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int ret = 0;
        int b = 0;
        for(int i = 0;i<13;i++){
            int len = i%2+1;
            while(s.substr(b,len) == simp[i]){
                b+=len;
                ret += step[i];
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    string str = "MCMXCIV";
    int ret = s.romanToInt(str);
    cout<<ret;
    return 0;
}

