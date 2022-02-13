#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<string> ret;
public:
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        vector<bool> visited(s.length(),false);
        string tmp="";
        help(s,visited,tmp);
        return ret;
    }
    void help(string &s,vector<bool> &visited,string tmp){
        int cnt = 0;
        char pre;
        bool done = true;
        for(int i = 0;i<visited.size();i++){
            if(visited[i]) continue;
            if(cnt>0&&s[i]==pre) continue;
            cnt++;
            pre = s[i];
            visited[i]=true;
            done = false;
            help(s,visited,tmp+s[i]);
            visited[i]=false;
        }
        if(done){
            ret.push_back(tmp);
        }
    }
};