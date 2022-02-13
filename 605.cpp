#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int idx = 0;
        int size = flowerbed.size();
        while(idx<size){
            if(flowerbed[idx]==1){
                idx+=2;
            }else if(flowerbed[idx]==0&&idx+1<size&&flowerbed[idx+1]==1){
                idx+=3;
            }else{
                idx+=2;
                cnt++;
            }
        }
        return cnt>=n;
    }
};