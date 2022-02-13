#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution_my {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> mp(26);
        int len = s.length();
        for(int idx=0;idx<len;idx++){
            mp[s[idx]-'a'].push_back(idx);
        }
        sort(mp.begin(),mp.end(),[](const auto& a,const auto& b)->bool{
            if(a.empty()){
                return false;
            }else if(b.empty()){
                return true;
            }else{
                return a.front()<b.front(); 
            }
        });
        int left = mp[0].front();
        int right = mp[0].back();
        vector<int> ret;
        for(int idx=1;idx<26;idx++){
            if(mp[idx].empty()){
                break;
            }
            if(mp[idx].front()<right){
                right = max(right,mp[idx].back());
            }else{
                ret.push_back(right-left+1);
                left = mp[idx].front();
                right = mp[idx].back();
            }
        }
        ret.push_back(right-left+1);
        return ret;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};


int main(){
    string s = "jybmxfgseq";
    Solution sl;
    sl.partitionLabels(s);
}