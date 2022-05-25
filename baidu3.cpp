
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
int main(){
    while(1){
        long double a,b,x,y;
        cin>>a>>b>>x>>y;
        long double m,n;
        long double ret = 0;
        m=a/x;n=0;
        if(m*y+n*x<=b){
            ret = max(ret,round(m+n));
        }
        m=0;n=a/y;        
        if(m*y+n*x<=b){
            ret = max(ret,round(m+n));
        }
        m=b/y;n=0;
        if(m*x+n*y<=a){
            ret = max(ret,round(m+n));
        }
        m=0;n=b/x;
        if(m*x+n*y<=a){
            ret = max(ret,round(m+n));
        }
        
        m=(a*x-b*y)/(pow(x,2)-pow(y,2));
        n=(a-m*x)/y;
        bool tmp = isnan(m)||isnan(n);
        if(!tmp){
            if(m>0&&n>0){
                ret = max(ret,round(m+n));
            }
        }
        cout<<round(ret)<<endl;
    }
}