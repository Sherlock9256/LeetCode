#include<unordered_map>
#include<iostream>
using namespace std;
struct Node {
    int key;
    int val;
    Node *next;
    Node *pre;
    Node(int k,int x) : key(k),val(x), next(nullptr), pre(nullptr) {}
};
class LRUCache {
    Node* head=nullptr;
    Node* tail=nullptr;
    int cnt=0;
    int cap;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        cout<<"get "<<key<<endl;
        cout<<mp[key]<<endl;
        if(mp[key]){
            Node* tmp = mp[key];
            if(tmp==head&&tmp==tail){
                
            }else if(tmp==head){
                head = head->next;
                head->pre = nullptr;
                tail->next = tmp;
                tmp->next = nullptr;
                tmp->pre = tail;
                tail = tmp;
            }else if(tmp==tail){

            }else{
                tmp->pre->next = tmp->next;
                tmp->next->pre = tmp->pre;
                tail->next = tmp;
                tmp->next = nullptr;
                tmp->pre = tail;
                tail = tmp;
            }
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    void put(int key, int value) {
        cout<<"put "<<key<<" "<<value<<endl;
        if(mp[key]!=nullptr){
            mp[key]->val=value;
            get(key);
        }else{
            if(!head){
                Node* tmp = new Node(key,value);
                mp[key] = tmp;
                head = tail = tmp;
                cnt++;
            }else{
                Node* tmp = new Node(key,value);
                mp[key] = tmp;
                tail->next = tmp;
                tmp->pre = tail;
                tail = tmp;
                cnt++;
            }
            if(cnt>cap){
                cout<<"delete"<<endl;
                cnt--;
                head->next->pre = nullptr;
                mp[head->key] = nullptr;
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }
};