#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<string> ret;
public:
    vector<string> removeInvalidParentheses(string s) {
        int l_delete=0,r_delete=0;
        for(char& chr:s){
            if(chr=='('){
                l_delete++;
            }
            if(chr==')'){
                if(l_delete){
                    l_delete--;
                }else{
                    r_delete++;
                }
            }
        }
        help(s,l_delete,r_delete,0);
        return ret;
    }
    void help(string s,int l_delete,int r_delete,int start){

        if(l_delete==0&&r_delete==0&&check(s)){
            ret.push_back(s);
            return;
        }
        for(int i =start;i<s.length();i++){
            if(s.size()-i<l_delete+r_delete)break;
            if(i>0&&s[i]==s[i-1]){
                continue;
            }
            if(s[i]=='('){
                help(s.substr(0,i)+s.substr(i+1),l_delete-1,r_delete,i);
            }else if(s[i]==')'){
                help(s.substr(0,i)+s.substr(i+1),l_delete,r_delete-1,i);
            }
        }
    }
    bool check(string s){
        int left=0,right=0;
        for(char& chr:s){
            if(chr=='('){
                left++;
            }
            if(chr==')'){
                if(left){
                    left--;
                }else{
                    right++;
                }
            }
        }
        return left==0&&right==0;
    }
};
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        char l = '(',r=')';
        int len = s.length();
        int left = 0,right = len-1;
        while(left<len&&s[left]=l){
            if(s[left]!=r){
                left_char+=s[left];
            }
            left++;
        }
        if(left==len){
            ret.push_back(left_char);
            return ret;
        } 

        while(right>left&&s[right]!=r){
            if(s[right]!=l){
                right_char+=s[right];
            }
            right--;
        }
        if(right==left){
            ret.push_back(left_char+right_char);
            return ret;
        } 

        vector<int> left_idxs,right_idxs;
        for(int i = left;i<=right;i++){
            if(s[i]==l){
                left_idxs.push_back(i);
            }else if(s[i]==r){
                right_idxs.push_back(i);
            }
        }
        string cur = "";
        int cnt = left_idxs.size()-right_idxs.size();
        if(cnt==0){
            ret.push_back(s.substr(left,right-left+1));
        }else if(cnt>0){
            help(ret,left_idxs.size()-1,left+1,right-1,cnt,l,cur,s,left_char,right_char);
        }else{
            help(ret,right_idxs.size()-1,left+1,right-1,-cnt,r,cur,s,left_char,right_char);
        }
        return ret;
    } 
    void help(vector<string>& ret,int total,int start,int right,int to_delete, char targ,string cur,string& s,string& left_char,string& right_char){
        // cout<<start<<","<<right<<","<<to_delete<<" "<<cur<<endl;
        if(total<to_delete){return;}
        // if(to_delete==0&&start>right){
        //     ret.push_back('('+cur+')');
        //     return;
        // }
        for(int i = start;i<=right;i++){
            if(s[i]!=targ){
                cur+=s[i];
                // cout<<cur<<endl;
            }else if(to_delete>0){
                //去重
                if(i<right&&s[i+1]==targ&&total>to_delete){
                    help(ret,total-1,i+1,right,to_delete,targ,cur+s[i],s,left_char,right_char);
                }else{
                    help(ret,total-1,i+1,right,to_delete,targ,cur+s[i],s,left_char,right_char);
                    help(ret,total-1,i+1,right,to_delete-1,targ,cur,s,left_char,right_char);
                }
                return;
            }else{
                help(ret,total-1,i+1,right,to_delete,targ,cur+s[i],s,left_char,right_char);
                return;
            }
        }
        ret.push_back(left_char+'('+cur+')'+right_char);
        return;
    }
};