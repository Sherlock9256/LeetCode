
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    int cnt=0;
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next)return head;
        int cnt=0;
        ListNode* tail=head;
        ListNode* pre=nullptr;
        while(cnt<k&&head){
            ListNode* next = head->next;
            head->next=pre;
            pre=head;
            head=next;
            cnt++;
        }
        if(cnt==k){
            ListNode* tmp = nullptr;
            tmp = reverseKGroup(head,k);
            tail->next=tmp;
            return pre;
        }else{
            head=pre;
            pre=nullptr;
            while(head){
                ListNode* next = head->next;
                head->next=pre;
                pre=head;
                head=next;
            }
            return pre;
        }
    }
};