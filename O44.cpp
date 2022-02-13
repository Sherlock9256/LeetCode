class Solution {
public:
    int findNthDigit(int n) {
        int ground = 0;
        int digit = 1;
        int base = 1;
        while(n>ground+digit*base*9){
            ground+=digit*base*9;
            digit++;
            base*=10;
        }
        int left_digit = n-ground;
        int num_cnt = left_digit/digit;
        int num_digit_cnt = left_digit%digit;
        int target_num = base+num_cnt-1;

        num_digit_cnt = digit-num_digit_cnt;
        while(num_digit_cnt>1){
            target_num/=10;
            num_digit_cnt--;
        }
        return target_num%10;
    }
};