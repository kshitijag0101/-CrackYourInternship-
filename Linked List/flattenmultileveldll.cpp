#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val){
        val=_val;
        prev=NULL;
        child=NULL;
        next=NULL;
    }
};
Node* insert(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL) return temp;
    Node*curr=head;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}
Node* sol(Node* head) {
    Node* prev=NULL,*curr=head;
    while(curr!=NULL){
        prev=curr;
        if(curr->child!=NULL){
            Node* tail=sol(curr->child);
            tail->next=curr->next;
            if(curr->next!=NULL){
                curr->next->prev=tail;
            }
            curr->next=curr->child;
            curr->child->prev=curr;
            curr->child=NULL;
            curr=tail->next;
            prev=tail;
        }
        else{
            curr=curr->next;
        }
    }
    return prev;
}
Node* flatten(Node* head) {
    sol(head);
    return head;
}
int main(){
    Node* head1=NULL,*head2=NULL;
    int n,m,x,val;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        head1=insert(head1,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        head2=insert(head2,x);
    }
    head1->next->child=head2;
    Node*res=flatten(head1);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}