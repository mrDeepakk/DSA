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
//  searching position of the element 
int search(int arr[],int start,int end,int val){
    int mid;
    end++;
    while (start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==val)
            return mid;
        else if(arr[mid]>val)
            end=mid-1;
        else if(arr[mid]<val)
            start=mid+1;
    }
    return -1;
}

// build tree using inorder and preorder array
node* buildTree(int preorder[],int inorder[],int start,int end){
    static int indx=0;
    if(start>end){
        return NULL;
    }

    int curr=preorder[indx];
    indx++;
    node*root=new node(curr);
    if(start==end)
        return root;
    
    int pos=search(inorder,start,end,curr);
    root->left=buildTree(preorder,inorder,start,pos-1);
    root->right=buildTree(preorder,inorder,pos+1,end);
    return root;

}

void display(node*root){
    if(root==NULL) return;

    display(root->left);
    
    display(root->right);
    cout<<root->data<<" ";
}
int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    int s=sizeof(inorder)/inorder[0]-1;

    node*root=buildTree(preorder,inorder,0,s);
    display(root);
    return 0;
}