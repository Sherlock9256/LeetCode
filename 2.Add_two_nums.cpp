#include<cstdlib>
#include<iostream>
#define NULL 0

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* root = new ListNode(0);
       int sum = l1->val + l2->val;
       int up = sum > 9 ? 1 : 0;
       sum %= 10;
       root->val = sum;
       ListNode* Cur = root;
       while(1)
       {

            l1 = l1==NULL?0:l1->next;
            l2 = l2==NULL?0:l2->next;
            //结合律的问题
            sum = (l1!=NULL?l1->val:0)  +  (l2!=NULL?l2->val:0) + up;

            if (sum == 0 && l1==0 && l2 ==0)
            {
                Cur->next = NULL;
                break;
            }

            up = sum > 9 ? 1 : 0;
            sum %= 10;
            ListNode* Next = new ListNode(sum);
            Cur->next = Next;
            Cur = Next;
       }
       return root;
    }
};

int main(){
    ListNode* F1 = new ListNode(5);
    ListNode* S1 = new ListNode(0);
    ListNode* T1 = new ListNode(3);

    ListNode* F2 = new ListNode(2);
    ListNode* S2 = new ListNode(0);
    ListNode* T2 = new ListNode(4);

    F1->next = S1;
    S1->next = T1;

    F2->next = S2;
    S2->next = T2;

    Solution s;

    ListNode* root = s.addTwoNumbers(F1,F2);

    while(root != NULL)
    {
        cout<<root->val<<" ";
        root = root->next;
    }

    return 0;
}