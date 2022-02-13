#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<int> dp(len2+1,0);
        int tmp,tmp2;
        for(int i = 0;i<len1;i++){
            tmp = 0;
            for(int j = 0;j<len2;j++){
                if(word1[i]==word2[j]){
                    tmp2=dp[j+1];
                    dp[j+1]=max(max(dp[j+1],dp[j]),tmp+1);
                    tmp = tmp2;
                }else{
                    tmp=dp[j+1];
                    dp[j+1]=max(dp[j+1],dp[j]);
                }
            }
        }
        return len1+len2-dp[len2];
    }
};