#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int len = s.length();
        int cnt = 1;
        int self = 1;
        int pre = 0;
        int tmp;
        for(int i = 1;i<len;i++){
            switch (s[i])
            {
            case '0':
                if(s[i-1]>'0'&&s[i-1]<'3'){
                    cnt=self;self=0;pre=cnt;
                }else{
                    return 0;
                }
                break;
            case '7':
            case '8':
            case '9':                
                if(s[i-1]>'0'&&s[i-1]<'2'){
                    cnt = cnt + self;
                    tmp = pre;
                    pre = self;
                    self = self + tmp;
                }else{
                    self = self + pre;
                    pre = 0;
                }
                break;
            default:
                if(s[i-1]>'0'&&s[i-1]<'3'){
                    cnt = cnt + self;
                    tmp = pre;
                    pre = self;
                    self = self + tmp;
                }else{
                    self = self + pre;
                    pre = 0;
                }
                break;
            }
        }
        return cnt;
    }
}; 