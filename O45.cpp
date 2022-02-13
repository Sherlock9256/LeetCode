#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](auto& a,auto& b)->bool{
            if(a==0){
                return true;
            }
            if(b==0){
                return false;
            }
            int tmp1=a;
            int base = 1;
            while(tmp1>0){
                tmp1/=10;
                base*=10;
            }
            tmp1 = a+b*base;
            int tmp2 = b;
            while(tmp2>0){
                tmp2/=10;
                base*=10;
            }
            tmp2 = b+a*base;
            return tmp1<tmp2;
        });
        string ret="";
        for(auto& a:nums){
            ret+=a;
        }
        return ret;
    }
};
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](auto& a,auto& b)->bool{
            if(a==0){
                return true;
            }
            if(b==0){
                return false;
            }
            string tmp1 = to_string(a)+to_string(b);
            string tmp2 = to_String(b)+to_string(a);
            return tmp1<tmp2;
        });
        string ret="";
        for(auto& a:nums){
            ret+=a;
        }
        return ret;
    }
};