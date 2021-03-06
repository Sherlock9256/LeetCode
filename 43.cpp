#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
    
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
       int m = num1.size(),n=num2.size();
       vector<int> int1(m),int2(n),rec(m+n,0);
       for(int i = 0;i<num1.length();i++){
           int1[i]=num1[i]-'0';
       }
       for(int j = 0;j<num2.length();j++){
           int2[j]=num2[j]-'0';
       }
       for(int i = m-1;i>=0;i--){
           for(int j = n-1;j>=0;j--){
               rec[i+j+1] += int1[i]*int2[j];
           }
       }
       for(int i = m+n-1;i>0;i--){
           rec[i-1]+=rec[i]/10;
           rec[i]=rec[i]%10;
       }
       int idx;
       idx = rec[0]==0?1:0;
       string ret="";
       while(idx<m+n){
           ret+=rec[idx]+'0';
           idx++;
       }
        return ret;
    }  
};



class Solution {
    
public:
    string multiply(string num1, string num2) {
        string ret="0";
        string tmp;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i = 0;i<num1.length();i++){
            tmp = mul(num2,num1[i],i);
            // cout<<tmp<<endl;
            ret = add(ret,tmp);
            // cout<<ret<<endl;
            // cout<<"--------"<<endl;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string mul(string& a,char b,int base){
        if(b=='0'||a=="0")return "0";
        string ret="";
        while(base){
            ret+='0';
            base--;
        }
        int add_=0;
        int multi,mod;
        for(int i=0;i<a.length();i++){
            multi = (b-'0')*(a[i]-'0') + add_;
            mod = multi%10;
            add_ = multi/10;
            ret+=('0'+mod);
        }
        if(add_){
            ret+=('0'+add_);
        }
        return ret;
    }
    string add(string& a,string& b){
        // cout<<"add: "<<a.length()<<" "<<b.length()<<endl;
        if(a.length()==0)return b;
        string ret = "";
        int add_ = 0;
        int l = 0;
        int sum_,mod;
        while(l<a.length()&&l<b.length()){
            sum_ = add_ + (a[l]-'0')+(b[l]-'0');
            mod = sum_%10;
            add_ = sum_/10;
            ret+=(mod+'0');
            // cout<<ret<<" "<<mod<<endl;
            l++;
        }
        while(l<a.length()){
            sum_ = add_ + (a[l]-'0');
            mod = sum_%10;
            add_ = sum_/10;
            ret+=(mod+'0');
            l++;
        }
        while(l<b.length()){
            sum_ = add_+(b[l]-'0');
            mod = sum_%10;
            add_ = sum_/10;
            ret+=(mod+'0');
            l++;
        }
        if(add_){
            ret+=('0'+add_);
        }
        return ret;
    }
};