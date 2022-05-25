#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//stack

class Solution {
public:
    int trap(vector<int>& height) {
        int ret;
        stack<int> stk;
        for(int i = 0;i<height.size();i++){
            while(!stk.empty()&&height[i]>=height[stk.top()]){
                int top = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int left = height[stk.top()];
                    int cur = height[top];
                    int right = height[i];
                    ret += (min(left,right)-cur)*(i-stk.top()-1);
                }
            }
            stk.push(i);
        }
        return ret;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int tmp=0;
        for(int i = 0;i<height.size();i++){
            tmp=tmp>height[i]?tmp:height[i];
            left[i]=tmp;
        }
        tmp=0;
        for(int i = height.size()-1;i>=0;i--){
            tmp=tmp>height[i]?tmp:height[i];
            right[i]=tmp;
        }
        int cnt=0;
        
        for(int i = 0;i<height.size();i++){
            cnt+=min(left[i],right[i])-height[i];
        }
        return cnt;
    }
};

//填满
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;

        int left = 0;
        int right = 0;
        int min_;
        int tmp;
        
        while(right<height.size()-1){
            while(right<height.size()-1&&height[right+1]<=height[right]){
                right++;
            }
            if(right==height.size()){
                break;
            }
            //out
            while(right<height.size()-1&&height[right+1]>=height[right]){
                right++;
            }
            
            min_ = min(height[left],height[right]);
            for(int i = left+1;i<right;i++){
                tmp = min_-height[i];
                ret += tmp>0?tmp:0;
                if(tmp>0){
                    height[i] = min_;
                }
            }

            if(height[right]>=height[left]){
                left = right;
            }
        }
        return ret;
    }
}; 

int main(){
    vector<int> nums = {3,36,2,1,74,52,1,2,1,2,0,1,1,4,2,1,4,5,3,89,78,74,4};
    Solution s;
    int ret = s.trap(nums);
    cout<<ret<<endl;
    return 0;
}