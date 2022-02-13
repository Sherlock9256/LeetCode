#include<vector>
#include<string>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

bool small(pair<string,int> a,pair<string,int> b){
    return a.first<b.first;
}
class Solution_my {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<pair<string,int>> ps;
        string str;
        pair<string,int> pr;
        for(int i = 0;i<strs.size();i++){
            str = strs[i];
            sort(str.begin(),str.end());
            pr.first = str;
            pr.second = i;
            ps.push_back(pr);
        }   
        sort(ps.begin(),ps.end(),small);

        vector<string> tmp;
        for(int i = 0;i<ps.size();i++){
            if(i>0&&ps[i].first!=ps[i-1].first){
                ret.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(strs[ps[i].second]);
        }
        ret.push_back(tmp);

        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


int main(){

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    s.groupAnagrams(strs);
    return 0;
}