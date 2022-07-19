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
ListNode* partition(ListNode* head, int x) {
    if(head==NULL || head->next==NULL) return head;
    vector<int> res;
    ListNode* curr=head;
    while(curr!=NULL){
        if(curr->val<x){
            res.push_back(curr->val);
        }
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL){
        if(curr->val>=x){
            res.push_back(curr->val);
        }
        curr=curr->next;
    }
    curr=head;
    int i=0;
    while(curr!=NULL){
        curr->val=res[i++];
        curr=curr->next;
    }
    return head;
}
int main(){
    ListNode* head=NULL;
    int n,x,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        head=insert(head,val);
    }
    cin>>x;
    ListNode* curr=partition(head,x);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}