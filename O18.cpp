#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            if(cur->val==val){
                if(!pre){
                    return cur->next;
                }else{
                    pre->next = cur->next;
                    return head;
                }
            }
            pre=cur;
            cur=cur->next;
        }
        return head;
    }
};