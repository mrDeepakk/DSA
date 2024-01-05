#include<iostream>
using namespace std;

struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};

node*insertBST(node*root,int val){
    if(root==NULL) return new node(val);

    if(root->data>val)
        root->left=insertBST(root->left,val);
    if(root->data<val)
        root->right=insertBST(root->right,val);
    return root;
}

void sumReplace(node*root){
    if(root==NULL) return;

    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left!=NULL)
        root->data+=root->left->data;
    if(root->right!=NULL)
        root->data+=root->right->data;
}

void preorder(node*root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
 
}

int main(){
    node*root=NULL;
    root=insertBST(root,3);
    insertBST(root,5);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,9);
    insertBST(root,7);
    preorder(root);
    cout<<endl;
    sumReplace(root);
    preorder(root);
    return 0;
}