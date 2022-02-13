#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> A;
        vector<ListNode*> B;
        while(headA){
            A.push_back(headA);
            headA = headA->next;
        }
        while(headB){
            B.push_back(headB);
            headB = headB->next;
        }
        ListNode* tmp = nullptr;
        while(A.size()>0&&B.size()>0){
            if(A.back()==B.back()){
                tmp = A.back();
                A.pop_back();
                B.pop_back();
            }else{
                break;
            }
        }
        return tmp;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        while(a!=b){
            a = a?a->next:headB;
            b = b?b->next:headA;
        }
        return a;
    }
};