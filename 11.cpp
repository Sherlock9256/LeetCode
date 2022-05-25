#include<vector>
#include<stack>
using namespace std;
class Solution {
    int ret = 0;
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int left=0,right=size-1;
        int tmp;
        while(left<right){
            tmp = (right-left)*min(height[left],height[right]);
            ret = ret>tmp?ret:tmp;
            if(height[left]<height[right]){
                left++;
            }else if(height[right]<=height[left]){
                right--;
            }
        }
        return ret;
    }  
};