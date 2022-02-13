#include<queue>
#include<iostream>
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        string ret="";
        TreeNode* tmp;
        while(!que.empty()){
            tmp=que.front();
            if(tmp){
                ret+=to_string(tmp->val)+',';
            }else{
                ret+="null,";
            }
            que.push(tmp->left);
            que.push(tmp->right);
        }
        return ret.substr(0,ret.length()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splited = split(data);
        int idx = 1;
        TreeNode* root;
        if(splited[0]!="null"){
            root= new TreeNode(decode(splited[0]));
        }else{
            root= nullptr;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        while(idx<splited.size()){
            tmp = que.front();
            que.pop();
            if(!tmp)continue;
            if(splited[idx]=="null"){
                tmp->left=nullptr;
            }else{
                tmp->left=new TreeNode(decode(splited[idx]));
            }
            idx++;
            if(splited[idx]=="null"){
                tmp->right=nullptr;
            }else{
                tmp->right=new TreeNode(decode(splited[idx]));
            }
            idx++;
        }
        return root;
    }
    vector<string> split(string& data){
        vector<string> ret;
        int begin = 0;
        int end= 0;
        while(end<data.length()){
            end++;
            if(end==data.length()||data[end]==','){
                ret.push_back(data.substr(begin,end-begin));
                begin = end+1;
                end++;
            }
        }
        return ret;
    }
    int decode(string& str){
        int base=1;
        int ret=0;
        for(int i = str.length()-1;i>0;i--){
            ret+=(str[i]-'0')*base;
            base*=10;
        }
        if(str[0]=='-'){
            return -ret;
        }else{
            ret+=(str[i]-'0')*base;
            return ret;
        }
    }
};