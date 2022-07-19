#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x), next(next) {}
};
ListNode* insert(ListNode* head,int x){
    ListNode* temp=new ListNode(x);
    if(head==NULL) return temp;
    ListNode*curr=head;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=temp;
    return head;
}
void reorderList(ListNode* head) {
    if(head==NULL || head->next==NULL) return;
    ListNode* slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* prev=NULL,*curr=slow,*temp;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    ListNode* node1=head,*node2=prev;
    while(node2->next!=NULL){
        temp=node1->next;
        node1->next=node2;
        node1=temp;
        temp=node2->next;
        node2->next=node1;
        node2=temp;
    }
}
int main(){
    ListNode* head=NULL;
    int n,x,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    reorderList(head);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}