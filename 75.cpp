#include<vector>
using namespace std;
class Solution_my {
public:
    void sortColors(vector<int>& nums) {

        vector<pair<int,int>> BE(3); 

        int b0 = -1,b1=-1,b2=-1,e0=-1,e1=-1,e2=-1;

        
        int len = nums.size();
        int i = 0;
        while(i<len){
            if(nums[i]==0){
                if(b1!=-1){
                    swap(nums[i],nums[b1]);
                    if(b0==-1){
                        b0=b1;
                    }
                    e0=b1;
                    if(b1==e1){
                        b1=e1=-1;
                    }else{
                        b1++;
                    }
                }else if (b2!=-1){
                    swap(nums[i],nums[b2]);                
                    if(b0==-1){
                        b0=b2;
                    }
                    e0=b2;
                    if(b2==e2){
                        b2=e2=-1;
                    }else{
                        b2++;
                    }
                }else{
                    if(b0==-1){
                        b0=i;
                    }
                    e0=i;
                }
            }
            if (nums[i]==1){
                if(b2!=-1){
                    swap(nums[i],nums[b2]);                
                    if(b1==-1){
                        b1=b2;
                    }
                    e1=b2;
                    if(b2==e2){
                        b2=e2=-1;
                    }else{
                        b2++;
                    }
                }else{
                    if(b1==-1){
                        b1=i;
                    }
                    e1=i;
                }
            }
            if (nums[i]==2){
                if(b2==-1){
                    b2=i;
                }
                e2=i;
            }
            i++;
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1,one = 0,two = nums.size();
        
        while(one<two){
            if(nums[one] == 0){
                swap(nums[one++],nums[++zero]);
            }else if(nums[one] == 2){
                swap(nums[one++],nums[--two]);
            }else{
                one++;
            }
        }
    }
};