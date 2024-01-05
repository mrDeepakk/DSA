#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};
// node* head1 = NULL;
// node *head2 = NULL;
void insert(node*head,int val){
    node*newnode = new node(val);
    node*temp=head;

    if(head==NULL){
        head = newnode;
        return;
    }
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    
}
void intersection(node*head1,node*head2,int pos){
    node*temp1=head1;
    node*temp2=head2;
    while(pos--){
        temp1 = temp1->next;
    }
    while (temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);
    insert(head1,6);
    insert(head1,7);
    // insert(head2,1);
    // insert(head2,9);
    // intersection(head1, head2, 2);

    print(head1);
    cout << endl;
    print(head2);
    return 0;
}