#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmpl1=l1;
        int add=0;
        ListNode* pre;
        ListNode* tail;
        while(l1&&l2){
            l1->val+=l2->val;
            l1->val+=add;
            add = l1->val/10;
            l1->val%=10;
            pre=l1;
            tail=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            l1->val+=add;
            add = l1->val/10;
            l1->val%=10;
            tail=l1;
            l1=l1->next;
            
        }
        if(l2)pre->next = l2;
        while(l2){
            l2->val+=add;
            add = l2->val/10;
            l2->val%=10;
            tail=l2;
            l2=l2->next;
        }
        if(add){
            tail->next = new ListNode(add);
        }
        return tmpl1;
    }
};