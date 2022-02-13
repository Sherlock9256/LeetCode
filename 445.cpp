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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> a1,a2;
        while(l1){
            a1.push_back(l1);
            l1=l1->next;
        }
        while(l2){
            a2.push_back(l2);
            l2=l2->next;
        }
        ListNode* last = nullptr;
        ListNode* pre = nullptr;
        int add = 0;
        while(a1.size()>0||a2.size()>0){
            pre=nullptr;
            if(a1.size()>0){
                pre=a1.back();
                a1.pop_back();
            }
            if(a2.size()>0){
                if(pre){
                    pre->val+=a2.back()->val;
                }else{
                    pre=a2.back();
                }
                a2.pop_back();
            }  
            pre->val+=add;
            if(pre->val>9){
                pre->val-=10;
                add=1;
            }else{
                add=0;
            }
            pre->next = last;
            last = pre;
        }
        ListNode* tmp = last;
        if(add==1){
            tmp = new ListNode(1,last);
        }
        return tmp;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        return addv(l1,l2,l1,l2,false,false,add);
    }
    ListNode* addv(ListNode*l,ListNode*r,ListNode*l1,ListNode*l2,bool a1,bool a2,int& add){
        if(!l&&!r) return nullptr;
        ListNode *tmp_l=l,*tmp_r=r;

        bool tmp_a1=a1,tmp_a2=a2;
        
        if(!tmp_l){tmp_l = l2;tmp_a1=true;} else{tmp_l=tmp_l->next;}
        if(!tmp_r){tmp_r = l1;tmp_a2=true;} else{tmp_r=tmp_r->next;}

        ListNode* follow = addv(tmp_l,tmp_r,l1,l2,tmp_a1,tmp_a2,add);
        ListNode* ret = new ListNode();
        if(a1){
            ret->val+=l->val;
        }else if(a2){
            ret->val+=r->val;
        }else if(add>0){
            ret->val += add;
        }else{
            return follow;
        }
        if(ret->val>9){
            ret->val-=10;
            add=1;
        }else{
            add=0;
        }
        ret->next = follow;
        return ret;
    
    }
};