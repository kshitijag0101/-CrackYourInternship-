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
ListNode* reverseList(ListNode* start,ListNode* end){
    ListNode* curr=start->next,*prev=start,*next,*temp=curr;
    while(curr!=end){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start->next=prev;
    temp->next=curr;
    return temp;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || k==1){
        return head;
    }
    ListNode* temp=new ListNode(0);
    temp->next=head;
    int count=0;
    ListNode* start=temp,*end=head;
    while(end!=NULL){
        count++;
        if(count%k==0){
            start=reverseList(start,end->next);
            end=start->next;
        }
        else{
            end=end->next;
        }
    }
    return temp->next;
}
int main(){
    ListNode* head=NULL;
    int n,x,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    cin>>k;
    head=reverseKGroup(head,k);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}