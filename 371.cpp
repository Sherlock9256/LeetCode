public:
    int getSum(int p, int q) {
        if(q==0)return p;
        unsigned int add = p&q;
        add<<=1;
        unsigned int mod = p^q;
        return getSum(mod,add);
    }
};




































class Solution {
public:
    int getSum(int p, int q) {
        unsigned a  = p;
        unsigned b = q;
        return (int)(b == 0 ? a : getSum((a ^ b), (a & b) << 1));
    }
};