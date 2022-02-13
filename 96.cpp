#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        unordered_map<int,int> mp;
        mp[1] = 1;
        for(int i = 2;i<n+1;i++){
            int right;
            mp[i] = 0;
            for(int left = 0;left<i;left++){
                right = i-left;
                mp[i] += mp[left]*mp[right];
            }
        }
        return mp[n];
    }
};