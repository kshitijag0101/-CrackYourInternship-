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
ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    int val=head->val;
    ListNode* temp=head->next;
    if(temp->val!=val){
        head->next=deleteDuplicates(temp);
        return head;
    }
    else{
        while(temp!=NULL && temp->val==val){
            ListNode* p=temp;
            temp=temp->next;
            delete p;
        }
        return deleteDuplicates(temp);
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
    ListNode* curr=deleteDuplicates(head);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}