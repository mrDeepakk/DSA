#include<iostream>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
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

// int height(node*root){
//     if(root==NULL) return 0;
//     int lheight=height(root->left);
//     int rheight=height(root->right);
//     return max(lheight,rheight)+1;
// }

// int diameter(node*root){
//     if(root==NULL) return 0;
//     int lHeight=height(root->left);
//     int rHeight=height(root->right);
//     int currDiameter=lHeight+rHeight+1;

//     int lDiameter=diameter(root->left);
//     int rDiameter=diameter(root->right);
//     return max(currDiameter,max(lDiameter,rDiameter));
// }

int diameter(node*root,int*height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter=diameter(root->left,&lh);
    int rDiameter=diameter(root->right,&rh);
    *height=max(lh,rh)+1;
    int curr=lh+rh+1;
    return max(curr,max(lDiameter,rDiameter));
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
    int height=0;
    cout<<endl<<diameter(root,&height);
    return 0;
}