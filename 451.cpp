#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();
        unordered_map<char,int> mp;
        for(int i = 0;i<len;i++){
            mp[s[i]] ++;
        }
        vector<vector<char>> bckt(len+1);
        for(auto& [chr,cnt]:mp){
            bckt[cnt].emplace_back(chr);
        }

        string ret;
        int cnt = 0;
        for(int i = len;i>0;i--){
            if(cnt==len){
                break;
            }
            for(int j = bckt[i].size()-1;j>=0;j--){
                for(int k = 0;k<i;k++){
                    ret.push_back(bckt[i][j]);
                    cnt++;
                }
            }
        }
        return ret;
    }
};