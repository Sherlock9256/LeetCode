#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution_my {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        ret.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++){
            tmp = ret.back();
            if(tmp[1]>=intervals[i][0]){
                tmp[1]=max(intervals[i][1],tmp[1]);
                if(ret.size()>0){
                  ret.pop_back();
                }
                ret.push_back(tmp);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};