#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const auto& a,const auto& b){
            return a[0]<b[0];
        });

        int size = points.size();
        int cnt = 1;
        int right = points[0][1];
        int idx = 1;
        while(idx<size){
            if(points[idx][0]<=right){
                right = min(right,points[idx][1]);
            }else{
                cnt++;
                right = points[idx][1];
            }
            idx++;
        }
        return cnt;
    }
};