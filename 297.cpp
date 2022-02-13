#include <string>
#include<vector>
#include<queue>
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
        vector<int> rec;
        queue<TreeNode*> que;
        int cnt = 1;
        que.push(root);
        while(!que.empty()){
            for(int i = 0;i<cnt;i++){
                if(que.front()){
                    rec.push_back(que.front()->val);
                    que.push(que.front()->left);
                    que.push(que.front()->right);
                }else{
                    rec.push_back(1111);
                }
                que.pop();
            }
            cnt = que.size();
        }
        string ret="";
        for(int i:rec){
            ret+=to_string(i);
            ret+=",";
        }
        // cout<<ret.substr(0,ret.length()-1)<<endl;
        return ret.substr(0,ret.length()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        int idx = 0;
        vector<int> token ;
        split(data,token,0,data.length());
        // cout<<token.size();
        // for(int a:token){
        //     cout<<a<<",";
        // }
        TreeNode* root;
        if(token[idx]==1111){
            root=nullptr;
        }else{
            root = new TreeNode(token[idx]);
        }
        idx++;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur;
        while(idx<token.size()){
            // cout<<idx<<" idx"<<endl;
            cur = que.front();
            if(token[idx]==1111){
                cur->left = nullptr;
            }else{
                cur->left = new TreeNode(token[idx]);
                que.push(cur->left);
            }
            idx++;
            if(token[idx]==1111){
                cur->right=nullptr;
            }else{
                cur->right = new TreeNode(token[idx]);
                que.push(cur->right);
            }
            idx++;
            que.pop();
            // cout<<cur->val<<" "<<cur->left->val<<" "<<cur->right->val<<endl;
        }
        // cout<<serialize(root);
        return root;
    }
    
    void split(string& data,vector<int>& ret,int idx,int len){
        int i = idx;
        for(;i<len&&data[i]!=',';i++){}
        string tmp = data.substr(idx,i-idx);
        if(tmp=="1111"){
            ret.push_back(1111);
        }else{
            ret.push_back(decode(data,idx,i-idx));
        }
        if(i!=data.length()){
            split(data,ret,i+1,len);
        }
    }
    int decode(string& data,int begin,int end){
        int base=1;
        int ret=0;
        for(int i = end;i>=begin;i--){
            ret += (data[i]-'0')*base;
            base*=10;
        }
        if(data[0]=='-'){
            ret = -ret;
        }else{
            ret += (data[0]-'0')*base;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));