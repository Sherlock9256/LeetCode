#include<cstdlib>
#include<iostream>
#include<climits>
using namespace std;
double rd(){
    return rand()/(double)RAND_MAX;
}

double pi(int times){
    int n=times;
    int cnt=0;
    while(times-->0){
        double x=rd();
        double y=rd();
        if(x*x+y*y<=1){
            cnt++;
        }
    }
    return (double)(cnt*4)/n;
}
int main(){
    cout<<pi(200000000)<<endl;
    int i=1;
}