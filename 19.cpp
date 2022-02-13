#include<iostream>
#include<map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        if(fast->next==nullptr) return head->next;
        ListNode* slow = head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        map<int,ListNode*> mp;
        int idx = 0;
        ListNode* p = head;
        while(p!=NULL){
            idx++;
            mp[idx] = p;
            p = p->next;
        }
        int tagt = idx-n+1;
        int pre = idx-n;
        int next = idx-n+2;
        
        //第一个
        if(mp[pre]==NULL){
            head = mp[next];
        }else{
            mp[pre]->next = mp[next];
        }

        return head;
    }
};