#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> arrs;
        for(char& a :tasks){
            if(mp.count(a)){
                arrs[mp[a]].second++;
            }else{
                pair<char,int> pr = {a,1};
                arrs.push_back(pr);
                mp[a]=arrs.size()-1;
            }
        }
        // sort(arrs.begin(),arrs.end(),[](auto& a,auto& b){
        //     return a.second>b.second;
        // });
        vector<int> cnts(arrs.size(),0);
        int ret = 0;
        bool done = true;
        int max_idx;
        bool in;
        int max_;
        while (1){      
            in = false;
            done = true;
            max_idx = 0;
            max_ = INT_MIN;
            for(int i = 0;i<arrs.size();i++){
                if(arrs[i].second!=0){
                    done = false;
                    if(cnts[i]==0){
                        in = true;
                        if(arrs[i].second>max_){
                            max_ = arrs[i].second;
                            max_idx = i;
                        }
                    }else{
                        cnts[i]--;
                    }
                }
            }
            if(in){
                arrs[max_idx].second--;
                cnts[max_idx] = n;
            }

            if(done){
                break;
            }
            ret++;
        }
        return ret;
    }
};