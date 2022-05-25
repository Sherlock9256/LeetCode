#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int two=0,three=0,five=0;
        vector<int> rec(n);
        rec[0]=1;
        for(int i = 1;i<=n;i++){
            rec[i] = min(min(rec[two]*2,rec[three]*3),rec[five]*5);
            if(rec[i]==rec[two]*2){
                two++;
            }
            if(rec[i]==rec[three]*3){
                three++;
            }
            if(rec[i]==rec[five]*5){
                five++;
            }
        }
        return rec[n-1];
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<int,bool> ok;
        vector<int> rec;
        rec.push_back(1);
        int idx = 0;
        int tmp_idx;
        while(rec.size()<n){
            tmp_idx=idx;
            idx += rec.size();
            for(int i = tmp_idx;i<rec.size();i++){
                int a=rec[i];
                if(!ok[a*2]){
                    ok[a*2]=true;
                    rec.push_back(a*2);
                    idx++;
                }
                if(!ok[a*3]){
                    ok[a*3]=true;
                    rec.push_back(a*3);
                }
                if(!ok[a*5]){
                    ok[a*5]=true;
                    rec.push_back(a*5);
                }
            }
        }
        sort(rec.begin(),rec.end());
        return rec[n-1];
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<int,bool> ok;
        ok[1]=true;
        int num = 1;
        int cnt = 1;
        while(cnt<n){
            num++;
            if(num%2==0&&ok[num/2]==true){
                ok[num]=true;
                cnt++;
            }else if(num%3==0&&ok[num/3]==true){
                ok[num]=true;
                cnt++;
            }else if(num%5==0&&ok[num/5]==true){
                ok[num]=true;
                cnt++;
            }else{
                ok[num]=false;
            }
        }
        return num;
    }
};