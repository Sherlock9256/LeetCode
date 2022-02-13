class Solution {
public:
    int getSum(int p, int q) {
        unsigned a  = p;
        unsigned b = q;
        return (int)(b == 0 ? a : getSum((a ^ b), (a & b) << 1));
    }
};