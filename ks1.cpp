#include <iostream>
#include <algorithm>
using namespace std;
float help(float& val,float prec){
    float tmpval = val;
    float l,r;
    if(val==1)return 1.;
    if(val==0)return 0.;
    if(val<0)val=-val;
    if(val>1){
        l=0;r=val;
    }else if(val<=1){
        l=0;r=1;
    }

    float mid;
    float ret;
    while(r-l>prec){
        mid = l+(r-l)/2;
        ret = mid*mid*mid;
        cout<<"l:"<<l<<"\tr:"<<r<<"\tret:"<<ret<<endl;
        if(abs(ret-val)<prec){
            break;
        }
        if(ret<val){
            l=mid+prec;
        }else if(ret>val){
            r=mid-prec;
        }else{
            break;
        }
    }
    mid = l+(r-l)/2;
    if(tmpval<0){
        mid = -mid;
    }
    return mid;
}
int main() {
    float val = 0.9;
    float ret = help(val,0.0001);
    cout<<ret;
}
//