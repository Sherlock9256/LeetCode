class Solution {
public:
    int lastRemaining(int n) {
        int gap=1;
        int mode = 1;
        int last = 1;
        int begin;
        while(last+gap<=n&&last+gap>0){
            begin = last + gap;
            int idx = 1;
            while(begin + idx*2*gap>0&&begin + idx*2*gap<=n){
                idx++;
            }
            idx--;
            last = begin+idx*2*gap;
            gap*=-2;
        }
        return last;
    }
};




















class Solution {
public:
    int lastRemaining(int n) {
        int begin = 1;
        int end = n;
        int gap = 1;
        bool left = true;
        while(end-begin!=0){
            if(left){
                begin = begin+gap;
                gap*=2;
                int cnts = (end-begin)/gap;
                end = begin+cnts*gap;
            }else{
                end = end-gap;
                gap*=2;
                int cnts = (end-begin)/gap;
                begin = end-cnts*gap;
            }
            left = !left;
        }   
        return begin;
    }
};