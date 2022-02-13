
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *odd_head,*odd_tail,*even_head,*even_tail,*tmp;
        odd_head=odd_tail=head;
        even_head=even_tail=head->next;
        while(even_tail){
            tmp = even_tail->next;
            if(!tmp){
                break;
            }
            odd_tail->next=tmp;
            odd_tail = tmp;
            tmp = odd_tail->next;
            even_tail->next = tmp;
            even_tail = tmp;
        }
        odd_tail->next = even_head;
        return  odd_head;
    }
};