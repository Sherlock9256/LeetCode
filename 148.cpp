#include<queue>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* res,*red;
        help(head,res,red);
        return res;
    }

    void help(ListNode* head,ListNode*& rehead,ListNode*& retail){
        if(!head||!head->next){
            rehead = head;
            retail = head;
            return;
        }
        ListNode* tmp,*mid,*tail;
        mid = head;
        tail = head;
        while(tail&&tail->next){
            mid = mid->next;
            tail = tail->next->next;
        }
        tmp = head;
        ListNode* small_head=nullptr;
        ListNode* small_tail=nullptr;
        ListNode* big_head=nullptr;
        ListNode* big_tail=nullptr;

        while(tmp){
            if(tmp!=mid){
                if(tmp->val<mid->val){
                    if(!small_head){
                        small_head = tmp;
                        small_tail = tmp;
                    }else{
                        small_tail->next=tmp;
                        small_tail = tmp;
                    }
                }else{
                    if(!big_head){
                        big_head = tmp;
                        big_tail = tmp;
                    }else{
                        big_tail->next = tmp;
                        big_tail = tmp;
                    }
                }
            }
        }
        if(small_head){
            small_tail->next = nullptr;
            ListNode* res,*red;
            help(small_head,res,red);
            rehead = res;
            red->next = mid;
        }else{
            rehead = mid;
        }

        if(big_head){
            big_tail->next = nullptr;
            ListNode* res,*red;
            help(big_head,res,red);
            retail = red;
            mid->next = res;
        }else{
            // mid->next = nullptr;
            retail = mid;
        }
        retail->next = nullptr;
    }
};