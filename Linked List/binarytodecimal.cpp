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
int getDecimalValue(ListNode* head) {
    int res=0;
    while(head){
        res=res*2;
        res+=head->val;
        head=head->next;
    }
    return res;
}
int main(){
    ListNode* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    int res=getDecimalValue(head);
    cout<<res<<endl;
}