#include<vector>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* tmp = head;
        Node* copy_tmp = new Node(-1);
        while(tmp){
            Node* newtmp;
            if(mp[tmp]==nullptr){
                newtmp = new Node(tmp->val);
                mp[tmp] = newtmp;
            }else{
                newtmp = mp[tmp];
            }
            copy_tmp->next = newtmp;
            Node* copy_rdm;
            if(tmp->random==nullptr){
                copy_rdm = nullptr;
            }else if(mp[tmp->random]==nullptr){
                copy_rdm = new Node(tmp->random->val);
                mp[tmp->random] = copy_rdm;
            }else{ 
                copy_rdm = mp[tmp->random];
            }
            newtmp->random = copy_rdm;
            copy_tmp = copy_tmp->next;
            tmp = tmp->next;
        }
        return mp[head];
    }
};