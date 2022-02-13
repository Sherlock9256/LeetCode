#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        map<char,int> sec;
        map<char,int> gue;
        for(int i = 0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                A++;
            }else{
                sec[secret[i]]++;
                gue[guess[i]]++;
            }
        }
        map<char,int>::iterator iter = gue.begin();
        while(iter!=gue.end()){
            B += min(sec[iter->first],gue[iter->first]);
            iter++;
        }


        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main(){
    
        map<char,int> sec;
        cout<<++sec['q']<<endl;
        return 0;
}