class Solution {
public:
    int findComplement(int num) {
        int tmp = num;
        int mask = 0;
        while(num){
            mask<<=1;
            mask+=1;
            num>>=1;
        }
        return mask^tmp;
    }
};