#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

unordered_map<char,double> mp;

struct node{
    node* left;
    node* right;
    double val;
    char mod;
    node(int v){
        mod = '=';
        val = v;
    }
    node(char v){
        if(mp.count(v)){
            mod = v;
            val = mp[v];
        }else{
            cout<<"error"<<endl;
        }
    }
    node(char mod,node*left,node* right){
        this->mod = mod;
        this->left = left;
        this->right = right;
        get();
    }

    double get(){
        switch (mod)
        {
        case '=':
            return val;
        case '+':
            val = left->get()+right->get();
            return val;
        case '-':
            val = left->get()-right->get();
            return val;
        case '*':
            val = left->get()*right->get();
            return val;
        case '/':
            val = left->get()/right->get();
            return val;
        default:
            if(mp.count(mod)){
                val = mp[mod];
                return val;
            }else{
                cout<<"error"<<endl;
                return -1.0;
            }
        }
    }

    void backward(double g){
        double cur = get();
        double r = right->get();
        double l = left->get();
        switch (mod)
        {
        case '=':
            break;
        case '+':
            left->backward(g);
            right->backward(g);
            break;
        case '-':
            left->backward(g);
            right->backward(-g);
            break;
        case '*':
            left->backward(g*right->get());
            right->backward(g*left->get());
            break;
        case '/':
            left->backward(g/right->get());
            right->backward(-g*l/(r*r));
            break;
        default:
            mp[mod]-=g;
            break;
        }
    }
};


node* parse(string str){
    unordered_map<char,int> opri;
    opri['+']=1;
    opri['-']=1;
    opri['*']=2;
    opri['/']=2;
    str = '(' + str + ')';
    stack<char> ops;
    stack<node*> nds;
    string digits="";
    char chrs='.';
    for(auto& chr:str){
        if(chr<='z'&&chr>='a'){
            chrs=chr;
        }else if(chr<='9'&&chr>='0'){
            digits+=chr;
        }else if (chr=='('){
            ops.push(chr);
        }else if (chr==')'){
            if(chrs!='.'){
                node* n = new node(chrs);
                nds.push(n);
                chrs='.';
            }
            if(digits!=""){
                node* n = new node(stoi(digits));
                nds.push(n);
                digits="";
            }
            while(ops.top()!='('){
                char bop = ops.top();
                ops.pop();
                node* right = nds.top();
                nds.pop();
                node* left = nds.top();
                nds.pop();
                node* n = new node(bop,left,right);
                nds.push(n);
            }
            ops.pop();
        }else{
            if(chrs!='.'){
                node* n = new node(chrs);
                nds.push(n);
                chrs='.';
            }
            if(digits!=""){
                node* n = new node(stoi(digits));
                nds.push(n);
                digits="";
            }
            if(ops.empty()){
                ops.push(chr);
            }else{
                char bop = ops.top();
                if(opri[bop]>=opri[chr]){
                    node* right = nds.top();
                    nds.pop();
                    node* left = nds.top();
                    nds.pop();
                    node* n = new node(bop,left,right);
                    ops.pop();

                    nds.push(n);
                    ops.push(chr);
                }else{
                    ops.push(chr);
                }
            }
        }
    }
    return nds.top();
}

int main(){
    mp['a']=4;
    mp['b']=5;
    while(1){
        cout<<"--------"<<endl;
        string str;
        cin>>str;
        node* ret = parse(str);
        cout<<ret->get()<<endl;
    }
}