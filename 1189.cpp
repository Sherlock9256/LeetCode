#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        for(auto& a:text){
            mp[a]++;
        }
        int ret = mp['b'];
        ret = ret>mp['a']?mp['a']:ret;
        ret = ret>mp['l']/2?mp['l']/2:ret;
        ret = ret>mp['o']/2?mp['o']/2:ret;
        ret = ret>mp['n']?mp['n']:ret;
        return ret;
    }
};