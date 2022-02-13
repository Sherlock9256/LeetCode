#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* p=head;
        while(p){
            n++;
            p=p->next;
        }
        int mod = n%k;
        int divide = n/k;
        int cur_size;
        vector<ListNode*> ret(k);
        p=head;
        ListNode* tmp;
        for(int i =0;i<k&&p;i++){  
            ret[i] = p;
            cur_size = divide+mod-->0?1:0;
            for(int j=0;j<cur_size-1;j++){
                p=p->next;
            }
            tmp = p->next;
            p->next=nullptr;
            p=tmp;
        }

        return ret;
    }
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* p=head;
        while(p){
            n++;
            p=p->next;
        }
        int mod = n%k;
        int divide = n/k;
        vector<ListNode*> ret;

        n=0;
        int cnt=1;
        ListNode* tmp = head;
        while(head){
            while(cnt<divide){
                head=head->next;
                cnt++;
            }
            if(mod>0){
                if(divide!=0){
                    head=head->next;
                    cnt++;
                }
                mod--;
            }
            ret.push_back(tmp);
            tmp = head->next;
            head->next=nullptr;
            head = tmp;
            cnt=1;
        }
        while(ret.size()<k){
            ret.push_back(nullptr);
        }
        return ret;
    }
};