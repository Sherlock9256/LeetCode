#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool loop = false;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2){
            p1=p1->next;
            p2=p2->next;
            if(p2){
                p2 = p2->next;
            }else{
                loop = false;
                break;
            }
            if(p2==p1){
                loop = true;
                break;
            }
        }
        return loop;
    }
};