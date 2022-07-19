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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL && headB==NULL) return NULL;
    ListNode* curr1=headA,*curr2=headB;
    while(curr1!=NULL && curr2!=NULL && curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
        if(curr1==curr2){
            return curr1;
        }
        if(curr1==NULL){
            curr1=headB;
        }
        if(curr2==NULL){
            curr2=headA;
        }
    }
    return curr1;
}
int main(){
    ListNode* headA=NULL,*headB=NULL;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        headA=insert(headA,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        headB=insert(headB,x);
    }
    ListNode *res=getIntersectionNode(headA,headB);
    if(res==NULL) cout<<"No intersection point";
    else cout<<"Intersected at : "<<res->val;
}