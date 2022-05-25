#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    while(1){

        string str;
        getline(cin,str);
        int len = str.length();
        for(auto& a:str){
            cout<<(int)a<<" ";
        }
        cout<<endl;
        cout<<"str: "<<str<<"\tlen: "<<len<<endl;
    }

}