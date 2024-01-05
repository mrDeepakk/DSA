#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*next;
        node(int val){
            data=val;
            next=NULL;
        }
};

node*insert(node*head,int val){
    if(!head) return new node(val);
    node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new node(val);
    return head;
}
void display(node*head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"Null"<<endl;
}
int main(){
    node*head=NULL;
   head=insert(head,1);
   head=insert(head,2);
   head=insert(head,3);
   head=insert(head,4);
   head=insert(head,5);
   head=insert(head,6);
   head=insert(head,7);

    display(head);
    
return 0;
}