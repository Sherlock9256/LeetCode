#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> rec(m+1,vector<int>(n+1,0));
        for(int i = 0;i<m+1;i++){
            rec[i][0]=i;
        }
        for(int j = 0;j<n+1;j++){
            rec[0][j]=j;
        }
        for(int i = 1;i<m+1;i++){
            for(int j = 1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    rec[i][j]=rec[i-1][j-1];
                }else{
                    rec[i][j] = min(rec[i-1][j-1]+1,min(rec[i-1][j],rec[i][j-1])+1);
                }
            }
        }
        return rec[m][n];
    }
};






class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(),len2=word2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        for(int i = 0;i<len1+1;i++){
            dp[i][0]=i;
        }
        for(int i = 0;i<len2+1;i++){
            dp[0][i]=i;
        }
        for(int i = 0;i<len1;i++){
            for(int j =0;j<len2;j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    dp[i+1][j+1] = min(dp[i][j]+1,min(dp[i][j+1],dp[i+1][j])+1);
                }
            }
        }
        return dp[len1][len2];
    }
};