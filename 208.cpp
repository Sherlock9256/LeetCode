#include<string>
#include<map>
#include<vector>
using namespace std;
struct Node {
    bool isleaf=false;
    Node* follower[26] = {nullptr};
};


class Trie {
private:
    Node* root = new Node();
public:

    Trie(){}
    
    void insert(string word) {
        insert(word,root);
    }

    void insert(string word,Node* node){
        if(word.length()==0){
            node->isleaf = true;
            return;
        }
        int ofst = word[0]-'a';
        if(!node->follower[ofst]){
            node->follower[ofst] = new Node();
        }
        insert(word.substr(1),node->follower[ofst]);
    }
    
    bool search(string word) {
        return search(word,root);
    }

    bool search(string word,Node* node){
        if(word.length()==0){
            if(node->isleaf){
                return true;
            }else{
                return false;
            }
        }
        int ofst=word[0]-'a';
        if(!node->follower[ofst]) return false;
        return search(word.substr(1),node->follower[ofst]);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,root);
    }

    bool startsWith(string prefix,Node* node){
        if(prefix.length()==0){
                return true;
        }
        int ofst = prefix[0]-'a';
        if(!node->follower[ofst]) return false;
        return startsWith(prefix.substr(1),node->follower[ofst]);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */