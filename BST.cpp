#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node*left,*right;
        int height;

        Node(int val){
            data=val;
            left=right=NULL;
        }
};

int height(Node*node){
        if(!node) return 0;
        return node->height;
    }
    Node*LR(Node*node){
        Node*r=node->right;
        Node*rl=r->left;
        r->left=node;
        node->right=rl;
        
        node->height=max(height(node->left),height(node->right))+1;
        r->height=max(height(r->left),height(r->right))+1;
        
        return r;
    }
    Node*RL(Node*node){
        Node*l=node->left;
        Node*lr=l->right;
        l->right=node;
        node->left=lr;
        node->height=max(height(node->left),height(node->right))+1;
        l->height=max(height(l->left),height(l->right))+1;
        return l;
    }
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(!node) return new Node(data);
        
        if(node->data<data) node->right=insertToAVL(node->right,data);
        else node->left=insertToAVL(node->left,data);
        
        node->height=max(height(node->left),height(node->right))+1;
        int balanceFactor=height(node->left)-height(node->right);
        if(balanceFactor>1){
            if(data<node->left->data) return RL(node);
            else{
                node->left=LR(node->left);
                return RL(node);
            }
        }
        if(balanceFactor<-1){
            if(data>node->right->data) return LR(node);
            else{
                node->right=RL(node->right);
                return LR(node);
            }
        }
        
        return node;
    }


int main(){
    

    return 0;
}