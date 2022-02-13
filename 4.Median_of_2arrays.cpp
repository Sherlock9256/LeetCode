#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int m = (len1 + len2) / 2;  //个数
        int dual =( len1 + len2 ) % 2;
        dual == 1 ? m ++ :0;
        int l1 = 0, r1 = len1 - 1;
        int m1,m2;

        if (len1 == 0){
            if(dual){
                return nums2[m-1];
            }else{
                return 0.5 * (nums2[m-1]+nums2[m]);
            }
        }else if (len2 == 0){
            if(dual){
                return nums1[m-1];
            }else{
                return  (nums1[m] + nums1[m-1]) * 0.5;
            }
        }else{
            while(l1 < r1){
                m1 = (l1 + r1) / 2;
                m2 = m - m1 - 1 -1;
                if(m2 < len2){
                    if (m1 + 1 < len1 && nums1[m1+1] < nums2[m2]){
                        l1 = m1 + 1;
                    }else if (m2 + 1 < len2 && nums2[m2+1] < nums1[m1]){
                        r1 = m1;
                    }else{
                        break;
                    }
                }else{
                    l1 = m1 + 1;
                }
            }
        }

        return 0;

    }
};

int main()
{
    vector<int> nums2 = {1,3};
    vector<int> nums1 = {2,4};
    Solution s;
    double ret = s.findMedianSortedArrays(nums1, nums2);
    cout << ret;
}