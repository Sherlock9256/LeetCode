#include<map>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};










/*---------------------------------------------------------------------------------------------------------*/


struct Node{
    Node(int k,int v){key=k;val=v;}
    Node* pre=nullptr;
    Node* next=nullptr;
    int key;
    int val;
    int visited = 0;
};

class LFUCache {
    map<int,pair<Node*,Node*>> freq;
    map<int,Node*> mp;
    int mini=1;
    int cap;
    int cur_cnt=0;
    void update(int key){
        if(cur_cnt>cap){
            auto& head = freq[mini].first;
            auto& tail = freq[mini].second;
            mp[tail->key]=nullptr;
            if(head==tail){
                head=nullptr;
                tail=nullptr;
            }else{
                tail=tail->pre;
                tail->next=nullptr;
            }
            cur_cnt--;
        }
        Node* cur = mp[key];
        if(cur->visited!=0){
            auto& head = freq[cur->visited].first;
            auto& tail = freq[cur->visited].second;
            auto& pre=cur->pre,& next=cur->next;
            if(!pre&&!next){
                head=nullptr;
                tail=nullptr;
                if(cur->visited==mini){
                    mini++;
                }
            }else if(pre&&!next){
                tail =tail->pre;
                tail->next=nullptr;
            }else if(!pre&&next){
                head=head->next;
                head->pre=nullptr;
            }else if(pre&&next){
                pre->next=next;
                next->pre=pre;
            }
            cur->pre=nullptr;
            cur->next=nullptr;
        }
        cur->visited++;
        if(cur->visited<mini){
            mini=cur->visited;
        }
        auto& head = freq[cur->visited].first;
        auto& tail = freq[cur->visited].second;
        if(!head){
            head = cur;
            tail = cur;
        }else{
            cur->next=head;
            head->pre=cur;
            head=cur;
        }
    }
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp[key]){
            update(key);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(mp[key]){
            update(key);
            mp[key]->val=value;
        }else{
            Node* tmp = new Node(key,value);
            mp[key]=tmp;
            cur_cnt++;
            update(key);
        }
    }
};