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

node* buildTree(int postorder[],int inorder[],int start,int end){
    static int indx=end;
    if(start>end){ 
        return NULL;
    }
    int curr=postorder[indx];
    indx--;
    node*root=new node(curr);
    if(start==end)
        return root;
    int pos=search(inorder,start,end,curr);
    root->right=buildTree(postorder,inorder,pos+1,end);
    root->left=buildTree(postorder,inorder,start,pos-1);
    
    
    return root;
}

void display(node*root){
    if(root==NULL) return;

    
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);

}
int main(){
    int postorder[]={3,2,1};
    int inorder[]={3,2,1};
    node*root=buildTree(postorder,inorder,0,4);
    display(root);
    
    return 0;
}