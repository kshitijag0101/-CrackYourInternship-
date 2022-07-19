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
ListNode* merge(ListNode* a,ListNode* b){
    ListNode* merged=new ListNode();
    ListNode* temp=new ListNode();
    merged=temp;
    while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            temp->next=a;
            a=a->next;
        }
        else{
            temp->next=b;
            b=b->next;
        }
        temp=temp->next;
    }
    while(a!=NULL){
        temp->next=a;
        a=a->next;
        temp=temp->next;
    }
    while(b!=NULL){
        temp->next=b;
        b=b->next;
        temp=temp->next;
    }
    return merged->next;
}
ListNode* middle(ListNode* head){
    ListNode* slow=head,*fast=head->next;
    while(slow->next!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* msort(ListNode* head){
    if(head->next==NULL) return head;
    ListNode* mid=middle(head);
    ListNode* head2=mid->next;
    mid->next=NULL;
    ListNode* finalhead=merge(msort(head),msort(head2));
    return finalhead;
}
int main(){
    ListNode* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    head=msort(head);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}