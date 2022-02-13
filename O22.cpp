#include<vector>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        int cnt = 0;
        while(cnt <k&&fast){
            fast = fast->next;
            cnt++;
        }
        if(cnt<k)return nullptr;
        ListNode* slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};