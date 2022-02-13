#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
    TreeNode* help(vector<int>& nums, int l,int r){
        if(l>r) return nullptr;
        int mid = l+(r-l)/2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = help(nums,l,mid-1);
        ret->right = help(nums,mid+1,r);
        return ret;
    }
};