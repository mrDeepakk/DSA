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

void rightView(node*root){

    queue<node*>q;
    q.push(root);
    while(!q.empty()){

        int n=q.size();
        for(int i=0; i<n; i++){
            node*curr=q.front();
            q.pop();

            if(i==n-1)
                cout<<curr->data<<" ";

            if(curr->left) q.push(curr->left);
                
            if(curr->right) q.push(curr->right);
        }
    }
    

}
void leftView(node*root){

    queue<node*>q;
    q.push(root);
    while (!q.empty()){
        int n=q.size();
        for(int i=1; i<=n; i++){
            node*curr=q.front();
            q.pop();
            if(i==1)
                cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
                
            if(curr->right) q.push(curr->right);
        }
    }
    

}

int main(){
    node*root=NULL;
    root=insertBST(root,3);
    insertBST(root,5);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,9);
    rightView(root);
    cout<<endl;
    leftView(root);
    return 0;
}