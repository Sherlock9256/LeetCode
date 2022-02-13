#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head&&!head->next)return head;
        ListNode* pre = nullptr;
        do{
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp; 

        }while(head);
        return pre;
    }
};