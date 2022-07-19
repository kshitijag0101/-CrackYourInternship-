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
void zigzaglist(ListNode* head){
    ListNode* curr=head;
    bool flag=true;
    while(curr->next!=NULL){
        if(flag){
            if(curr->val>curr->next->val) swap(curr->val,curr->next->val);
        }
        else{
            if(curr->val<curr->next->val) swap(curr->val,curr->next->val);
        }
        curr=curr->next;
        flag=!flag;
    }
}
int main(){
    ListNode* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    zigzaglist(head);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}