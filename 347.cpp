#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution_my {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int num:nums){
            mp[num] = mp[num] + 1;
        }
        vector<vector<int>> bckt(nums.size()+1);
        
        map<int,int>::iterator iter = mp.begin();
        while(iter!=mp.end()){
            bckt[iter->second].push_back(iter->first);
            iter++;
        }

        vector<int> ret;
        try{
            for (int i = nums.size();i>0;i--){
                if(bckt[i].size()==0){
                    continue;
                }
                for(int j = 0;j<bckt[i].size();j++){
                    if(ret.size()<k){
                        ret.push_back(bckt[i][j]);
                    }else{
                        throw 1;
                    }
                }
            }
        }catch(int i){
            
        }
        return ret;
    }
};

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }
        decltype(cmp) tmp;
        decltype(cmp) * ttmp;
        decltype(&cmp) tmpp;

        auto greater = []( int a, int b ) { return a > b; };

        priority_queue <int, std::vector<int>, decltype(greater)> Q(greater);

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
