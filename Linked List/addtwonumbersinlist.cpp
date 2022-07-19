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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root=new ListNode();
    ListNode* temp=root;
    int c=0;
    while(l1!=NULL || l2!=NULL || c){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=c;
        c=sum/10;
        ListNode *node=new ListNode(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return root->next;
}
int main(){
    ListNode* l1=NULL,*l2=NULL;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        l1=insert(l1,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        l2=insert(l2,x);
    }
    ListNode *curr=addTwoNumbers(l1,l2);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}