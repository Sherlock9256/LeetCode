#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)return nullptr;
        Node* left,*right;
        help(root,left,right);
        left->left = right;
        right->right = left;
        return left; 
    }
    void help(Node* root,Node*& leftmost,Node*& rightmost){
        if(!root->left){
            leftmost = root;
        }else{
            Node* n_rightmost;
            help(root->left,leftmost,n_rightmost);
            n_rightmost->right = root;
            root->left = n_rightmost;
        }
        if(!root->right){
            rightmost = root;
        }else{
            Node* n_leftmost;
            help(root->right,n_leftmost,rightmost);
            root->right = n_leftmost;
            n_leftmost->left = root;
        }
    }
};