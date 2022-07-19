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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len=0;
    for(ListNode* curr=head;curr!=NULL;curr=curr->next){
        len++;
    }
    if(len<n) return head;
    ListNode *curr=head,*prev=NULL;
    for(int i=1;i<len-n+1;i++){
        prev=curr;
        curr=curr->next;
    }
    if(prev==NULL){
        head=curr->next;
    }
    else{
        prev->next=curr->next;
    }
    return head;
}
int main(){
    ListNode* head=NULL;
    int n,x,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    cin>>m;
    ListNode *res=removeNthFromEnd(head,m);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}