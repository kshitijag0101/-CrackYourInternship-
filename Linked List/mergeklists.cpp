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
ListNode* sortedmerge(ListNode* a,ListNode* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    ListNode* head=NULL,*tail=NULL;
    if(a->val<=b->val){
        head=tail=a;
        a=a->next;
    }
    else{
        head=tail=b;
        b=b->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    if(a==NULL) tail->next=b;
    else tail->next=a;
    return head;
    
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return NULL;
    ListNode* temp=lists[0];
    for(int i=1;i<lists.size();i++){
        temp=sortedmerge(temp,lists[i]);
    }
    return temp;
}
int main(){
    ListNode* head1=NULL,*head2=NULL;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        head1=insert(head1,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        head2=insert(head2,x);
    }
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    ListNode* head=mergeKLists(lists);
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}