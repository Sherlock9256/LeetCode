#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution_3{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};


class Solution_2{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode();
        ListNode* ret = tmp;
        while(l1||l2){
            if(l1&&l2){
                if(l1->val<l2->val){
                    tmp->next = l1;
                    tmp = l1;
                    l1=l1->next;
                }else{
                    tmp->next = l2;
                    tmp = l2;
                    l2=l2->next;
                }
            }else if(l1){
                tmp->next = l1;
                tmp = l1;
                l1=l1->next;
            }else if(l2){
                tmp->next = l2;
                tmp = l2;
                l2=l2->next;
            }
        }
        return ret;
    }
};

class Solution_1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(!l1&&!l2){
            return NULL;
        }
        ListNode* head = nullptr;
        ListNode* pre = nullptr;
        if(l1->val>=l2->val){
            head = l2;
            l2 = l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }
        pre = head;

        while(l1&&l2){
            if(l1->val>=l2->val){
                pre->next = l2;
                pre = pre->next;
                l2 = l2->next;
            }else{
                pre->next = l1;
                pre = pre->next;
                l1 = l1->next;
            }
        }
        
        if(!l1){
            pre->next = l2;
        }else if(!l2){
            pre->next = l1;
        }else{
            cout<<"error"<<endl;
        }
        return head;
    }
};
