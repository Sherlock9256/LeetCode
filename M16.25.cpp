#include<map>
using namespace std;

struct Node{
    Node(int k,int v){key=k;val = v;}
    int key;
    int val;
    Node* pre;
    Node* next;
};

class LRUCache {
    int cap;
    int cur_cnt=0;
    map<int,Node*> mp;
    Node* head = nullptr;
    Node* tail = nullptr;
    void update(Node* cur){
        Node* pre,*next;
        if(!pre){
            //head
        }else if(pre&&!next){
            //tail
            Node* tpre=tail->pre;
            tpre->next = nullptr;
            head->pre=tail;
            tail->next = head;
            head = tail;
            tail = tpre;
        }else{
            //middle
            pre->next = next;
            next->pre = pre;
            head->pre = cur;
            cur->next = head;
            cur->pre = nullptr;
            head = cur;
        }
    }
    void insert(Node* cur){
        if(!head){
            head = cur;
            tail = cur;
        }else{
            head->pre = cur;
            cur->next = head;
            head = cur;
        }
        cur_cnt++;
        if(cur_cnt>cap){
            int key = tail->val;
            mp[key]=nullptr;
            tail = tail->pre;
            delete tail->next;
            tail->next=nullptr;
            cur_cnt--;
        }
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp[key]){
            update(mp[key]);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp[key]){
            mp[key]->val = value;
            update(mp[key]);
        }else{
            mp[key] = new Node(key,value);
            insert(mp[key]);
        }
    }
};
