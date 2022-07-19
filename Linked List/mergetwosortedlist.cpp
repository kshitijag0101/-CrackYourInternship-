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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ListNode* head=NULL,*tail=NULL;
    if(list1->val<=list2->val){
        head=tail=list1;
        list1=list1->next;
    }
    else{
        head=tail=list2;
        list2=list2->next;
    }
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            tail->next=list1;
            tail=list1;
            list1=list1->next;
        }
        else{
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
    }
    if(list1==NULL) tail->next=list2;
    else tail->next=list1;
    return head;
}
int main(){
    ListNode* list1=NULL,*list2=NULL;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        list1=insert(list1,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        list2=insert(list2,x);
    }
    ListNode *res=mergeTwoLists(list1,list2);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}