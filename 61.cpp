

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        int cnt=0;
        ListNode* p =head;
        while(p){
            cnt++;
            p=p->next;
        }
        k=k%cnt;
        ListNode* fast = head;
        ListNode* slow = head;
        while(k){
            fast=fast->next;
            if(!fast)fast = head;
            k--;
        }
        if(!fast)return nullptr;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next = head;
        ListNode* ret = slow->next;
        slow->next = nullptr;
        return ret;
    }
};