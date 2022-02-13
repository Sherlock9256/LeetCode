#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        vector<vector<int>> ret;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        for(int i =0;i<=n;i++){
            search(ret,cur,nums,n,0,i);
        }
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,vector<int>& nums,int n,int idx,int size){
        if(cur.size()<size){
            int tmp = -15;
            for(int i =idx;i<n;i++){
                if(nums[i]!=tmp){
                    tmp = nums[i];
                    cur.push_back(nums[i]);
                    search(ret,cur,nums,n,i+1,size);
                    cur.pop_back();
                }

            }
        }else{
            ret.push_back(cur);
        }
    }
};

int main(){
    Solution s;
    vector<int> p = {1,2,2};
    s.subsetsWithDup(p);
}