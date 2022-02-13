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