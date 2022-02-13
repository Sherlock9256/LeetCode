#include<iostream>
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
    ListNode* reverseList(ListNode* head) {
        if(head){
            return reverse(head);
        }else{
            return head;
        }
    }   

    ListNode* reverse(ListNode* head){
        ListNode* last;
        if(head->next){
            last = reverse(head->next);
            head->next->next = head;    
            head->next = nullptr;
        }else{
            last = head;
        }
        return last;
    }
};

class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        vector<ListNode*> cur;
        ListNode* last,*tmp=head;

        while(tmp){
            cur.push_back(tmp);
            tmp=tmp->next;
        }
        last = cur.back();
        tmp = last;
        cur.pop_back();
        while(cur.size()>0){
            tmp->next = cur.back();
            tmp = cur.back();
            tmp->next = nullptr;
            cur.pop_back();
        }
        return last;
    }
};

class Solution_3 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* curnext = head->next;
        head->next = nullptr;
        ListNode* tmp;
        while(curnext){
            tmp = curnext->next;
            curnext->next = head;
            head = curnext;
            curnext = tmp;
        }
        return head;
    }
};