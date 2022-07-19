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
ListNode* sortList(ListNode* head) {
    vector<int> list;
    ListNode* curr=head;
    while(curr!=NULL){
        list.push_back(curr->val);
        curr=curr->next;
    }
    sort(list.begin(),list.end());
    curr=head;
    int i=0;
    while(curr!=NULL){
        curr->val=list[i++];
        curr=curr->next;
    }
    return head;
}
int main(){
    ListNode* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    ListNode* curr=sortList(head);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}