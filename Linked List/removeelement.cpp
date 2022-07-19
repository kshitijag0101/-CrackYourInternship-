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
ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return head;
    while(head!=NULL && head->val==val){
        head=head->next;
    }
    ListNode* prev,*curr=head;
    while(curr!=NULL){
        if(curr->val!=val){
            prev=curr;
        }
        else{
            prev->next=curr->next;
        }
        curr=curr->next;
    }
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
    cin>>val;
    ListNode *res=removeElements(head,val);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}