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
    stack<ListNode*> first,second;
    while(l1){
        first.push(l1);
        l1=l1->next;
    }
    while(l2){
        second.push(l2);
        l2=l2->next;
    }
    int c=0;
    ListNode* nextnode=NULL;
    while(!first.empty() || !second.empty() || c){
        int n1=0,n2=0;
        if(!first.empty()){
            n1=first.top()->val;
            first.pop();
        }
        if(!second.empty()){
            n2=second.top()->val;
            second.pop();
        }
        int sum=n1+n2+c;
        ListNode* node=new ListNode(sum%10);
        c=sum/10;
        node->next=nextnode;
        nextnode=node;
    }
    return nextnode;
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