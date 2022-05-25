#include<iostream>
#include<string>
using namespace std;
int ret = 0;
void check(string& str,int l,int r,int len){
    bool one=false,zero=false;
    while(l>=0&&r<len){
        if(str[l]==str[r]){
            if(str[l]=='0'){
                zero=true;
            }
            if(str[l]=='1'){
                one=true;
            }
            if(zero&&one){
                int tmp = r-l+1;
                ret = ret>tmp?ret:tmp;
            }
            l--;
            r++;
        }else{
            break;
        }
    }
}
int main(){
    while(1){
        string str;cin>>str;
        ret=0;
        int len = str.length();
        for(int i=5;i<len-1;i++){
            check(str,i,i,len);
            check(str,i,i+1,len);
        }
        cout<<ret<<endl;
        int i=5;
    }

}