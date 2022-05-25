
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre;
        ListNode* ret=new ListNode();
        pre=ret;
        while(head){
            pre->next=head;
            if(!head->next||head->val!=head->next->val){
                pre=head;
                head=head->next;
            }else{
                ListNode*cur=head;
                while(cur&&cur->val==head->val){
                    cur=cur->next;
                }
                pre->next=cur;
                head=cur;
            }
        }
        return ret->next;
    }
};