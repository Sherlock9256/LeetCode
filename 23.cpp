#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* pre_head = new ListNode(-50000);
        ListNode* pre = pre_head;
        int k = lists.size();
        int min_i = -1;
        int min = 50000;
        do{
            min = 50000;
            min_i = -1;
            for(int i = 0;i<k;i++){
                if(lists[i]){
                    if(lists[i]->val<min){
                        min = lists[i]->val;
                        min_i = i;
                    }
                }
            }
            if(min!=50000){
                pre->next = lists[min_i];
                pre = pre->next;
                lists[min_i] = lists[min_i]->next;
            }
        }while(min!=50000);
        
        return pre_head->next;
    }
};