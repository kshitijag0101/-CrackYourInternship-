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
void sortList(ListNode* head) {
    ListNode* curr=head;
    int count[3]={0};
    while(curr!=NULL){
        count[curr->val]+=1;
        curr=curr->next;
    }
    curr=head;
    int i=0;
    while(curr!=NULL){
        if(count[i]==0) i++;
        else{
            curr->val=i;
            count[i]--;
            curr=curr->next;
        }
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
    sortList(head);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}