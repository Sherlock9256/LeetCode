#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m=first.length(),n=second.length();
        if(abs(m-n)>1)return false;
        if(m>n){
            int tmp=m;
            m=n;
            n=tmp;
            string tmps=first;
            first=second;
            second=tmps;
        }
        int l =0,r=0;
        int cnt=0;
        while(l<m&&r<n){
            if(first[l]==second[r]){
                l++;r++;
            }else{
                if(m!=n){
                    r++;
                }else{
                    l++;r++;
                }
                cnt++;
                if(cnt>1) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m=first.length(),n=second.length();
        vector<vector<int>> rec(m+1,vector<int>(n+1,0));
        for(int i = 0;i<m+1;i++){
            for(int j= 0;j<n+1;j++){
                if(i==0){
                    rec[0][j]=j;
                }else if(j==0){
                    rec[i][0]=i;
                }else{
                    if(first[i-1]==second[j-1]){
                        rec[i][j]=min(rec[i-1][j-1],min(rec[i][j-1],rec[i-1][j])+1);
                    }else{
                        rec[i][j]=min(rec[i-1][j-1],min(rec[i][j-1],rec[i-1][j]))+1;
                    }
                }
            }
        }
        return rec[m][n]==1||rec[m][n]==0;
    }
};