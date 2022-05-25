#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    int cur_id=1;
    int valid=1;
    unordered_map<string,int> id;
    unordered_map<int,string> id2str;
    unordered_map<int,vector<int>> mp;
    vector<vector<string>> ret;
    int len=INT_MAX;
public:
    void insert(vector<int>& path){
        vector<string> rec;
        for(auto& i:path){
            if(i<valid){
                rec.push_back(id2str[i]);
            }
        }
        ret.push_back(rec);
    }
    void help(int begin,int end,vector<bool>& visited){
        queue<vector<int>> pathque;
        vector<int> tmp;tmp.push_back(begin);
        visited[begin]=true;
        pathque.push(tmp);
        int cnt=1;
        int length=0;
        bool find=false;
        vector<bool> curvisited(cur_id,false);
        while(!pathque.empty()){
            for(int i = 0;i<cnt;i++){
                vector<int> cur=pathque.front();
                pathque.pop();
                int tail=cur.back();
                if(tail==end){
                    find=true;
                    insert(cur);
                }
                for(auto& next:mp[tail]){
                    if(!visited[next]){
                        curvisited[next]=true;
                        cur.push_back(next);
                        pathque.push(cur);
                        cur.pop_back();
                    }
                }
            }
            if(find){
                break;
            }
            cnt=pathque.size();
            length++;
            for(int i=0;i<visited.size();i++){
                visited[i]=visited[i] || curvisited[i];
            }
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        id[beginWord]=cur_id++;
        id2str[id[beginWord]]=beginWord;
        for(auto& tmp:wordList){
            if(!id[tmp]){
                id[tmp]=cur_id++;
                id2str[id[tmp]]=tmp;
            }
        }
        valid=cur_id;
        for(int idd=1;idd<valid;idd++){
            string str=id2str[idd];
            int pid=idd;
            int qid;
            for(int i= 0;i<str.length();i++){
                char c = str[i];
                str[i]='*';
                if(!id[str]){
                    id[str]=cur_id++;
                    id2str[id[str]]=str;
                }
                qid=id[str];
                mp[pid].push_back(qid);
                mp[qid].push_back(pid);
                str[i]=c;
            }
        }
        ////////////////
        if(id[endWord]){
            vector<bool> visited(cur_id,false);
            help(id[beginWord],id[endWord],visited);
        }
        return ret;
    }
};

class Solution {
    int cur_id=1;
    int valid=1;
    unordered_map<string,int> id;
    unordered_map<int,string> id2str;
    unordered_map<int,vector<int>> mp;
    vector<vector<string>> ret;
    int len=INT_MAX;
public:
    void help(int begin,int end,vector<bool>& visited,vector<int> tmp){
        if(begin==end){
            if(tmp.size()>len){
                
            }else if(tmp.size()==len){
                vector<string> rec;
                for(auto& i:tmp){
                    if(i<valid){
                        rec.push_back(id2str[i]);
                    }
                }
                ret.push_back(rec);
            }else{
                len = tmp.size();
                ret.clear();
                vector<string> rec;
                for(auto& i:tmp){
                    if(i<valid){
                        rec.push_back(id2str[i]);
                    }
                }
                ret.push_back(rec);
            }
        }else{
            if(tmp.size()>=len){
                return;
            }else{
                for(auto& next:mp[begin]){
                    if(!visited[next]){
                        visited[next]=true;
                        tmp.push_back(next);
                        help(next,end,visited,tmp);
                        tmp.pop_back();
                        visited[next]=false;
                    }
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        id[beginWord]=cur_id++;
        id2str[id[beginWord]]=beginWord;
        for(auto& tmp:wordList){
            if(!id[tmp]){
                id[tmp]=cur_id++;
                id2str[id[tmp]]=tmp;
            }
        }
        valid=cur_id;
        for(int idd=1;idd<valid;idd++){
            string str=id2str[idd];
            int pid=idd;
            int qid;
            for(int i= 0;i<str.length();i++){
                char c = str[i];
                str[i]='*';
                if(!id[str]){
                    id[str]=cur_id++;
                    id2str[id[str]]=str;
                }
                qid=id[str];
                mp[pid].push_back(qid);
                mp[qid].push_back(pid);
                str[i]=c;
            }
        }
        ////////////////
        if(id[endWord]){
            vector<bool> visited(cur_id,false);
            vector<int> tmp;
            tmp.push_back(id[beginWord]);
            help(id[beginWord],id[endWord],visited,tmp);
        }
        return ret;
    }
};