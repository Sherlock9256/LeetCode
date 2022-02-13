#include<vector>
#include<iostream>
using namespace std;

class Solution_second{
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        search(ret,cur,nums,nums.size());
        return ret;
    }
    void search(vector<vector<int>>& ret,vector<int>& cur,vector<int>& nums,int n){
        if(cur.size()==n){
            ret.push_back(cur);
        }else{
            for(int i = 0;i<n;i++){
                if(nums[i]!=-100){
                    cur.push_back(nums[i]);
                    nums[i]=-100;
                    search(ret,cur,nums,n);
                    nums[i] = cur.back();
                    cur.pop_back();
                }
            }
        }

    }
};

class Solution_my {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> idty(nums.size());
        for(int i = 0;i<nums.size();i++){
            idty[i]=true;
        }
        vector<vector<int>> combs;
        vector<int> comb;
        search(combs,comb,nums,idty);
        return combs;
    }

    void search(vector<vector<int>>& combs,vector<int> comb,vector<int>& nums,vector<bool>& idty){
        bool find = false;
        for(int i = 0;i<nums.size();i++){
            if(idty[i]){
                find = true;
                idty[i]=false;
                comb.push_back(nums[i]);
                search(combs,comb,nums,idty);
                comb.pop_back();
                idty[i]=true;
            }else{
                continue;
            }
        }
        if(!find){
            combs.push_back(comb);
        }
    }

};
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

int main(){
    vector<bool> p;
    cout<<p[0]<<endl;
    return 0;
}