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
    }
    double help(int a,int b,int cnt){
        if(cnt%2==1){
            return b;
        }else{
            return (a+b)/2.;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m<n){
            int mid1,mid2;
            int median =(m+n)/2;
            int l = 0,r=m-1;
            while(l<=r){
                mid1=l+(r-l)/2;
                mid2=median-mid1-2;
                if(nums1[mid1]<nums2[mid2]){
                    if(mid1==m-1){
                        return help(nums2[mid2],nums2[mid2+1],m+n);
                    }else if(nums1[mid1+1]>=nums2[mid2]){
                        return help(nums2[mid2],min(nums1[mid1+1],nums2[mid2+1]),m+n);
                    }else{
                        l=mid1+1;
                    }
                }else{
                    if(nums2[mid2+1]>=nums1[mid1]){
                        if(mid1==m-1){
                            return help(nums1[mid1],nums2[mid2+1],m+n);
                        }else{
                            return help(nums1[mid1],min(nums1[mid1+1],nums2[mid2+1]),m+n);
                        }
                    }else{
                        r=mid1-1;
                    }
                }
            }
            if(l==0){
                if(median==n-1){
                    return help(nums2[median],,m+n);
                }else{

                }
            }
            if(r==m-1){

            }
        }
    }
    double help(int a,int b,int cnt){
        if(cnt%2==1){
            return b;
        }else{
            return (a+b)/2.;
        }
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(),size2=nums2.size();
        int median_cnt = (size1+size2)/2;
        bool odd = (size1+size2)%2 != 0;
        int cnt = 0;
        int i = 0,j=0;
        bool find = false;
        int lower = 0;
        int left_right = 0;
        while(i<size1&&j<size2){
            if(nums1[i]>=nums2[j]){
                j++;
                left_right = 2;
            }else{
                i++;
                left_right = 1;
            }
            cnt++;
            if (cnt==median_cnt){
                if(left_right==1){
                    lower = nums1[i-1];
                }else if(left_right==2){
                    lower = nums2[j-1];
                }else{
                    cout<<"error1"<<endl;
                }
                find = true;
                break;
            }
        }

        if(find){
            int upper = -1;
            if(i<size1&&j<size2){
                upper = 0;
                if(nums1[i]>=nums2[j]){
                    upper = nums2[j];
                }else{
                    upper = nums1[i];
                }
            }else if(i==size1){
                upper = nums2[j];
            }else if(j==size2){
                upper = nums1[i];
            }else{
                cout<<"error2"<<endl;
            }
            if(odd){
                return upper;
            }else{
                return (lower+upper)/2.0;
            }
        }else{
            if(i==size1){
                int idx = median_cnt-size1-1;
                if(odd){
                    return nums2[idx+1];
                }else{
                    return (nums2[idx]+nums2[idx+1])/2.0;
                }
            }else if(j==size2){
                int idx = median_cnt-size2-1;
                if(odd){
                    return nums1[idx+1];
                }else{
                    return (nums1[idx]+nums1[idx+1])/2.0;
                }
            }else{
                cout<<"error3"<<endl;
            }
        }
        return -100.0;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    double ret = s.findMedianSortedArrays(nums1,nums2);
    cout<<ret<<endl;
    return 0;
}