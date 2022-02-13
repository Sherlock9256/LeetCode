#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

// + 43
class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        bool first = false;
        int nega = 1;
        for(char i : str){
            if(!first){
                if(i == 45){
                    first = true;
                    nega = -1;
                }else if(i == 43){
                    first = true;    
                }else if(i >= 48 && i <= 57){
                    first = true;
                    ret += i - 48;
                }else if(i != 32){
                    break;
                }
                //负号溢出问题
            }else{

                if(!(i >= 48 && i <= 57)){
                    break;
                }

                if(ret > INT_MAX/10 ||( ret == INT_MAX/10 && i >= 55)){
                    return INT_MAX;
                }

                if(ret < INT_MIN/10 ||( ret == INT_MIN/10 && i >= 56)){
                    return INT_MIN;
                }
                ret = ret*10 + (i - 48)*nega ;

            }
        }
        return ret;
    }
};

int main(){
    string str = "+332";
    Solution s;
    int ret = s.myAtoi(str);
    cout << ret;
    return 0;
}