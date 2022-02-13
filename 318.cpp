#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> map;
        int tmp;
        for(auto& s:words){
            tmp = 0;
            for(auto& p:s){
                tmp|= 1<<(p-'a');
            }
            map.push_back(tmp);
        }
        int ret = 0;
        for(int i = 0;i<words.size();i++){
            for(int j =0;j<words.size();j++){
                if((map[i]&map[j])==0){
                    tmp = words[i].length()*words[j].length();
                    ret = tmp>ret?tmp:ret;
                }
            }
        }
        return ret;
    }
};