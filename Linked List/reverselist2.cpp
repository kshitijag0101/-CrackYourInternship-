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
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head==NULL) return NULL;
    ListNode* curr=head,*prev=NULL;
    while(left>1){
        prev=curr;
        curr=curr->next;
        left--;
        right--;
    }
    ListNode *start=prev,*tail=curr,*temp;
    while(right>0){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        right--;
    }
    if(start!=NULL) start->next=prev;
    else head=prev;
    tail->next=curr;
    return head;
}
int main(){
    ListNode* head=NULL;
    int n,x,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    int left,right;
    cin>>left>>right;
    ListNode* res=reverseBetween(head,left,right);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}