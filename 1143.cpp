#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length();
        int size2 = text2.length();
        vector<int> cnt(size2+1,0);
        int tmp1=0;
        int tmp2=0;
        for(int i = 0;i<size1;i++){
            tmp1=0;
            tmp2=0;
            for(int j=0;j<size2;j++){
                if(text1[i]==text2[j]){
                    tmp2=cnt[j+1];
                    cnt[j+1] = max(max(tmp1+1,cnt[j]),cnt[j+1]);
                    tmp1=tmp2;
                }else{
                    tmp2=cnt[j+1];
                    cnt[j+1] = max(cnt[j],cnt[j+1]);
                    tmp1=tmp2;
                }
            }
        }
        return cnt[size2];
    }
};