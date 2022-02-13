#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int min(int a,int b){
        return a>b?b:a;
    }

    int MymaxArea(vector<int>& height) {
        int len = height.size();
        int ret = 0;
        int tmp ;
        for(int i = 0; i < len - 1; i++){
            for(int j = i+1; j < len; j++){
                tmp = (min(height[i],height[j])*(j-i));
                ret =  tmp > ret ? tmp : ret;
            }
        }
        return ret;
    }

    int maxArea(vector<int>& height){
        int ret = 0;
        int l = 0,r = height.size() - 1;
        ret = min(height[l],height[r])*(r-l);
        int tmp;
        while(l < r){
            if(height[l] > height[r]){
                r--;
            }else if(height[l] < height[r]){
                l++;
            }else{
                height[l+1] > height[r-1] ? l++ : r--;
            }
            tmp = min(height[l],height[r])*(r-l);
            ret = ret < tmp ? tmp:ret;
        }

        return ret;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
   
    int ret = s.maxArea(height);
    cout << ret;
    return 0;
}