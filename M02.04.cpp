#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre = nullptr;
        ListNode* follow = nullptr;
        ListNode* tmppre = pre,* tmpfollow=follow;
        while(head){
            if(head->val<x){
                if(pre){
                    pre->next = head;
                    pre=pre->next;
                }else{
                    pre = head;
                    tmppre=head;
                }
            }else{
                if(follow){
                    follow->next = head;
                    follow = follow->next;
                }else{
                    follow=head;
                    tmpfollow=head;
                }
            }
            head=head->next;
        }
        ListNode* ret;
        if(!tmppre){
            ret = tmpfollow;
        }else if(!tmpfollow){
            ret =  tmppre;
        }else{
            pre->next=nullptr;
            follow->next=nullptr;
            pre->next = tmpfollow;
            ret =  tmppre;
        }
        return ret;
    }
};