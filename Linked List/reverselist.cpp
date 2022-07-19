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
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* rest_head=reverseList(head->next);
    ListNode* rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
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
    ListNode* res=reverseList(head);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}