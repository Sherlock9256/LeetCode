
class Solution_wrong {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int mid ;
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid*mid<x){
                l = mid+1;
            }else if(mid*mid>x){
                r = mid - 1;
            }else{
                return mid;
            }
        }
        return l; 
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
