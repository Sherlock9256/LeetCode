#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        int cnt = 0;
        int pre =INT_MIN;
        for(auto& i:intervals){
            if(i[0]<pre){
                cnt++;
            }else{
                pre = i[1];
            }
        }
        return cnt;
    }
};



















bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

class Solution_my {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int idx = 1;
        int cnt = 1;
        vector<int> ret={0};
        while(idx<intervals.size()){
            if(intervals[idx][0]>=intervals[ret[cnt-1]][1]){
                cnt++;
                ret.emplace_back(idx);
            }
            idx++;
        }
        return intervals.size()-cnt;
    }
};


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
