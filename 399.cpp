#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
    int cnt = 0;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        for(auto& eq:equations){
            if(!mp.count(eq[0])){
                mp[eq[0]]=cnt;
                cnt++;
            }
            if(!mp.count(eq[1])){
                mp[eq[1]]=cnt;
                cnt++;
            }
        }
        vector<vector<double>> rec(cnt,vector<double>(cnt,0));
        for(int i = 0;i<equations.size();i++ ){
            rec[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            rec[mp[equations[i][1]]][mp[equations[i][0]]] = 1/values[i];
        }
        vector<double> ret;
        for(auto& q:queries){
            if(!mp.count(q[0])||!mp.count(q[1])){
                ret.push_back(-1.0);
                continue;
            }
            vector<bool> visited(cnt,false);
            ret.push_back(help(visited,rec,mp[q[0]],mp[q[1]]));
        }
        return ret;
    }
    double help(vector<bool>& visited,vector<vector<double>> &rec,int src,int trg){
        if(rec[src][trg]!=0)return rec[src][trg];
        double ret = -1.0;
        double tmp;
        visited[src]=true;
        for(int i = 0;i<cnt;i++){
            if(visited[i]) continue;
            if(rec[src][i]==0.||rec[src][i]==-1.0) continue;
            tmp = help(visited,rec,i,trg);
            if(tmp!=-1.0){
                ret = tmp*rec[src][i];
                break;
            }
        }
        rec[src][trg] = ret;
        return ret;
    }
};



























class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int idx = 0;
        
        unordered_map<string,int> str2idx;
        int len = equations.size();
        for(int i = 0;i<len;i++){
            //?
            if(!str2idx.count(equations[i][0])){
                str2idx[equations[i][0]] = idx;
                idx++;
            }
            if(!str2idx.count(equations[i][1])){
                str2idx[equations[i][1]] = idx;
                idx++;
            }
        }
        vector<unordered_map<int,double>> direct_mp(idx,unordered_map<int,double>());
        for(int i = 0;i<len;i++){
            int here = str2idx[equations[i][0]];
            int there = str2idx[equations[i][1]];
            direct_mp[here][there] = values[i];
            direct_mp[there][here] = 1/values[i];
        }

        vector<double> ret;
        for(auto& qry:queries){
            if(!str2idx.count(qry[0])||!str2idx.count(qry[1])){
                ret.push_back(-1.0);
                continue;
            }
            vector<bool> visited(idx,false);
            int here = str2idx[qry[0]];
            int there = str2idx[qry[1]];
            visited[here] = true;
            double tmp = help(visited,here,there,direct_mp);
            ret.push_back(tmp);
            direct_mp[here][there] = tmp;
            direct_mp[there][here] = 1/tmp;
        }
        return ret;
    }

    double help(vector<bool>& visited,int here,int there,vector<unordered_map<int,double>>& direct_mp){
        if(here==there){
            return 1.0;
        }
        auto & prs = direct_mp[here];

        for(auto& p :prs){
            if(visited[p.first]==false){
                visited[p.first] = true;
                if(p.second==-1.0){
                    continue;
                }
                // if(prs[i].first==there){
                //     return prs[i].second;
                // }else{
                double ret = help(visited,p.first,there,direct_mp);
                if(ret!=-1.0){
                    double tmp = ret*p.second;
                    direct_mp[here][there] = tmp;
                    direct_mp[there][here] = 1/tmp;
                    return tmp;
                }
                // }
            }
        }

        // direct_mp[here][there] = -1.0;
        // direct_mp[there][here] = -1.0;
        return -1.0;
    }
};