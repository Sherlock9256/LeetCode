#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),[](auto& a,auto& b){
            return a.length()>b.length()||(a.length()==b.length()&&a<b);
        });
        for(auto& str:dictionary){
            int i=0,j=0;
            while(i<s.length()&&j<=str.length()){
                if(s[i]!=str[j]){
                    i++;
                }else{
                    i++;
                    j++;
                }
            }
            if(j==str.length()){
                return str;
            }
        }
        return "";
    }
};



















bool order(string & a,string &b){
    if(a.length()>b.length() || (a.length()==b.length() && a<b)){
        return true;
    }
    return false;
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),order);
        int p,q;
        for(int i = 0;i<dictionary.size();i++){
            p=0;
            q=0;
            while(p<s.length()&&q<dictionary[i].length()){
                if(s[p]==dictionary[i][q]){
                    p++;
                    q++;
                }else{
                    p++;
                }
            }
            if(q==dictionary[i].length()){
                return dictionary[i];
            }
        }
        return "";
    }
};

int main(){
    string str = "abpcplea";
    vector<string> dic = {"ale","apple","monkey","plea"};
    Solution s;
    s.findLongestWord(str,dic);
}