#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        int step[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string simp[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int cnt = 0;
        for(int i = 0; i < 13; i ++){
            cnt = num/step[i];
            for(int j = 0;j<cnt;j++){
                ret+=simp[i];
            }
            num%=step[i];
        }
        return ret;
    }
};

int main(){
    Solution s;
    int num = 1;
    string ret = s.intToRoman(num);
    cout<<ret;
    return 0;
}