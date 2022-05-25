class Solution {
    string ret = "0.";
    int cnt=30;
public:
    string printBin(double num) {
        int idx = 1;
        int idx_cnt=0;
        while(idx<=30&&num>0){
            double base = pow(2,-idx);
            while(num>=base){
                num-=base;
                idx_cnt++;
            }
            ret+=to_string(idx_cnt);
            idx++;
            idx_cnt=0;
        }
        if(num>0)return "ERROR";
        return ret;
    }
};