#include<string>
#include<algorithm>
#include<vector>
using namespace std;

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