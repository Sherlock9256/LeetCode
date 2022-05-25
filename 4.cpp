#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int m=nums1.size(),n=nums2.size();
        int cnt = m+n;
        int median;
        if(cnt%2==0){
            median = cnt/2;
        }else{
            median = cnt/2+1;
        }

        int l = 0;
        int r = m;
        int mid1,mid2;
        int left1,left2,right1,right2;
        while(l<=r){
            mid1 = (l+r)/2;
            mid2 = median-mid1;
            if(mid2<0){
                r=mid1-1;
            }else if(mid2>n){
                l=mid1+1;
            }else{
                if(mid1==0){
                    left1=INT_MIN;
                }else{
                    left1=nums1[mid1-1];
                }
                if(mid2==0){
                    left2=INT_MIN;
                }else{
                    left2=nums2[mid2-1];
                }
                if(mid1==m){
                    right1=INT_MAX;
                }else{
                    right1=nums1[mid1];
                }
                if(mid2==n){
                    right2=INT_MAX;
                }else{
                    right2=nums2[mid2];
                }
                if(max(left1,left2)<=min(right1,right2)){
                    return help(max(left1,left2),min(right1,right2),m+n);
                }else{
                    if(left1>left2){
                        r=mid1-1;
                    }else{
                        l=mid1+1;
                    }
                }
            }
        }
        return -1.;
    }
    
    double help(int a,int b,int cnt){
        if(cnt%2==1){
            return a;
        }else{
            return (a+b)/2.;
        }
    }
};
