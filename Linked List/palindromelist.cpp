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
ListNode* reverseList(ListNode* root){
    if(root==NULL || root->next==NULL) return root;
    ListNode* rest_head=reverseList(root->next);
    ListNode* rest_tail=root->next;
    rest_tail->next=root;
    root->next=NULL;
    return rest_head;
}
bool isPalindrome(ListNode* head) {
    if(head==NULL) return true;
    ListNode* slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* rev=reverseList(slow->next);
    ListNode* curr=head;
    while(rev!=NULL){
        if(rev->val!=curr->val) return false;
        curr=curr->next;
        rev=rev->next;
    }
    return true;
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
    bool res=isPalindrome(head);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}