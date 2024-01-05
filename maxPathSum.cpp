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




int main(){
    node*root=NULL;
    root=insertBST(root,3);
    insertBST(root,5);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,9);
    
    cout<<endl;

    return 0;
}