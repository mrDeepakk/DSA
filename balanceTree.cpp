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

int height(node*root){
    if(root==NULL)
        return 0;
    return height(root->left)+height(root->right)+1;
}

bool isBalance(node*root){
    if(root==NULL) return true;
    
    if(isBalance(root->left)==false)
        return false;
    if(isBalance(root->right)==false)
        return false;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(abs(lheight-rheight)<=1)
        return true;
    else
        return false;
    
}

bool isBal(node*root,int &hi){
    int lh=0,rh=0;
    if(root==NULL) return true;

    if(isBal(root->left,lh)==false)
        return false;
    if(isBal(root->right,rh)==false)
        return false;
    hi=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}

int main(){
    node*root=NULL;
    root=insertBST(root,3);
    insertBST(root,5);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,9);
    // insertBST(root,7);
    int h=0;
    if(isBal(root,h))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;
    return 0;
}