#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node *next;
        int data;
        node(int val){
            data = val;
            next = NULL;
        }
};

void insert(node*&head,int val){
    node*newnode = new node(val);
    if(head==NULL){
        head = newnode;
        return;
    }
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
node*reverse(node*&head){
    // iterative way to reverse linked list 
    // node*prev=NULL;
    // node*curr=head;
    // node*nxtptr;
    // while(curr!=NULL){
    //     nxtptr=curr->next;
    //     curr->next=prev;

    //     prev=curr;
    //     curr=nxtptr;
    // }
    // return prev;

    // recursive way to reverse the linked list
    if(head==NULL || head->next==NULL) return head;
    node*newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}
node*reversek(node*head,int k){
    node*prev=NULL;
    node*curr=head;
    node*nxtptr;
    int count=0;
    while(curr!=NULL && count<k){
        nxtptr=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nxtptr;
        count++;
    }
    if(nxtptr!=NULL)
        head->next=reversek(nxtptr,k);

    return prev;

}
void show(node*&head){
    node*temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    node *head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    
    show(head);
    node* rev=reversek(head,2);
    show(rev);

    return 0;
}