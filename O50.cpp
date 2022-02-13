#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> chrcnt;
        for(auto& a:s){
            chrcnt[a]++;
        }
        for(auto& a:s){
            if(chrcnt[a]==1)return a;
        }
        return ' ';
    }
};