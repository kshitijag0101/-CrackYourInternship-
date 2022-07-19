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
int multiplyTwoLists(ListNode* list1, ListNode* list2) {
    long long N= 1000000007;
    int num1=0,num2=0;
    while(list1!=NULL || list2!=NULL){
        if(list1){
            num1=((num1*10)%N)+list1->val;
            list1=list1->next;
        }
        if(list2){
            num2=((num2*10)%N)+list2->val;
            list2=list2->next;
        }
    }
    return ((num1%N)*(num2%N))%N;
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
    int res=multiplyTwoLists(list1,list2);
    cout<<res<<endl;
}