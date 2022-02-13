#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a=a.length()-1,len_b=b.length()-1;
        int add = 0;
        int tmp;
        string ret;
        while(add>0||len_a>=0||len_b>=0){
            tmp = add;
            if(len_a>=0) tmp += a[len_a]-'0';
            if(len_b>=0) tmp += b[len_b]-'0';
            add = tmp>1?1:0;
            tmp = tmp>1?tmp-2:tmp;
            ret.push_back(tmp+'0');
            len_a--;
            len_b--;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};