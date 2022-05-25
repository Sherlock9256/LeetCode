#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];
        int len = ret.length();
        for(int i = 1;i<strs.size();i++){
            for(int j = 0;j<strs[i].length()&&j<len;j++){
                if(strs[i][j]!=ret[j]){
                    len=j;
                    break;
                }
            }
            if(len==0)break;
            if(len>strs[i].length()){
                len=strs[i].length();
            }
        }
        return ret.substr(0,len);
    }
};