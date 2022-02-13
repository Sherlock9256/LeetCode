class Solution {
    int target = 1;
public:
    int countDigitOne(int n) {
        int p = INT_MAX;
        // cout<<p<<endl;
        int base=1;
        int tmpn=n;
        while(n>0){
            n/=10;
            if(n>0){
                base*=10;
            }
        }
        return help(tmpn,base);
    }
    int help(int n,int base){
        cout<<n<<","<<base<<endl;
        if(n==0)return 0;
        int ret = 0;
        int num = n/base;
        if(num>target){
            ret+=base;
        }else if(num==target){
            ret+=n%base+1;
        }else{
            ret+=0;
        }
        ret+=num*help(base-1,base/10);
        ret+=help(n%base,base/10);
        return ret;
    }
};