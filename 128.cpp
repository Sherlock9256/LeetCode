#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        vector<bool> visited(size,false);
        unordered_map<int,int> mp;
        for(int i = 0;i<size;i++){
            mp[nums[i]]=i;
        }
        int ret=0;
        int tmp=0;
        for(int i = 0;i<size;i++){
            if(visited[i]) continue;
            tmp=0;
            visited[i]=true;
            int left=nums[i];
            int right=nums[i];
            while(mp.count(left-1)){
                left=left-1;
                visited[mp[left]]=true;
            }
            while(mp.count(right+1)){
                right=right+1;
                visited[mp[right]]=true;
            }
            tmp=right-left+1;
            ret = ret>tmp?ret:tmp;
        }
        return ret;
    }
};