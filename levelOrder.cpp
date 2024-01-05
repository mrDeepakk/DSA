#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// node structure 
struct node{
    int data;
    node* left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertBST(node*root,int val){
    if(root==NULL)  
        return new node(val);
    if(root->data>val)
        root->left=insertBST(root->left,val);
    if(root->data<val)
        root->right=insertBST(root->right,val);
    return root;
}

void levelOrder(node*root){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int levelSum(node*root,int k){   // Kth level sum
    if(root==NULL)
        return -1;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k){
                sum+=n->data;
            }
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
void inorder(node*root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node*root=NULL;
    root=insertBST(root,3);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,8);
    insertBST(root,9);
    // printing the value of  the nodes
    // levelOrder(root);
    // cout<<endl;
    // cout<<levelSum(root,1)<<endl;
    inorder(root);
    return 0;
}