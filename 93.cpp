#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    vector<string> ret;
    vector<int> rec;
public:
    vector<string> restoreIpAddresses(string s) {
        help(s,0,0);
        return ret;
    }
    void help(string& s, int cnt,int idx){
        if(cnt==4&&idx==s.length()){
            string tmp="";
            for(int i = 0;i<4;i++){
                tmp+=to_string(rec[i]);
                if(i<3)tmp+=".";
            }
            ret.push_back(tmp);
            return;
        }
        if(idx==s.length()){
            return;
        }
        if(cnt==4){
            return;
        }
        if(s[idx]=='0'){
            rec.push_back(0);
            help(s,cnt+1,idx+1);
            rec.pop_back();
            return;
        }
        int tmp=0;
        for(int i = idx;i<s.length();i++){
            tmp = tmp*10 + s[i]-'0';
            if(tmp>0&&tmp<256){
                rec.push_back(tmp);
                help(s,cnt+1,i+1);
                rec.pop_back();
            }else{
                break;
            }
        }
    }
};


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ret;
        if(len>12||len<4) return ret;

        vector<int> pts={0};
        track(ret,s,pts,1,len);
        return ret;

    }
    void track(vector<string> & ret,string s,vector<int> pts,int idx,int len){
        if(pts.size()==4){
            string tmp = s.substr(pts.back(),len-pts.back());
            int tmp_len = tmp.length();
            if((tmp[0]=='0'&&tmp_len==1)||(tmp_len<4&&stoi(tmp,tmp_len)<256)){
                cout<<"IN"<<endl;
                while(pts.size()>1){
                    s.insert(pts.back(),".");
                    pts.pop_back();
                }
                ret.push_back(s);
                return;
            }
        }else{
            for(int i = idx;i<len;i++){
                int tmp_len = i-pts.back();
                string tmp = s.substr(pts.back(),tmp_len);
                
                if((tmp[0]=='0'&&tmp_len==1)||(tmp_len<4&&stoi(tmp,tmp_len)<256)){
                    pts.push_back(i);
                    for(int ppp=0;ppp<pts.size();ppp++){
                        cout<<pts[ppp]<<" ";
                    }
                    cout<<endl;
                    track(ret,s,pts,i+1,len);
                    pts.pop_back();
                    for(int ppp=0;ppp<pts.size();ppp++){
                        cout<<pts[ppp]<<" ";
                    }
                    cout<<endl;
                }else{
                    return;
                }
            }
        }
    }
    int stoi(string s,int len){
        int ret = 0;
        int cnt = 1;
        while(len>0){
            len--;
            ret += (s[len]-'0')*cnt;
            cnt*=10;
        }
        return ret;
    }
};

int main(){
    string s="25525511135";
    Solution sl;
    sl.restoreIpAddresses(s);
    return 0;
}