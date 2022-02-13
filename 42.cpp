#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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