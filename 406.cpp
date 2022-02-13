#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& a,const auto& b){
            return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        vector<vector<int>> ret;
        int size = people.size();
        int idx = 0;
        while(idx<size){
            ret.insert(ret.begin() + people[idx][1],people[idx]);
            idx++;
        }
        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};