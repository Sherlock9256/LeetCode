#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp;
        vector<int> rec = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";
        return help(num,mp,rec);
    }
    string help(int num,unordered_map<int,string>& mp,vector<int>& rec){
        int i = 0;
        while(i<rec.size()&&num>=rec[i]){
            i++;
        }
        i--;
        if(i>=0){
            return mp[rec[i]]+help(num-rec[i],mp,rec);
        }else{
            return "";
        }
    }
};