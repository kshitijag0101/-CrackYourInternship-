#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* insert(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL) return temp;
    Node*curr=head;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=temp;
    return head;
}
Node* copyRandomList(Node* head) {
    if(head==NULL) return NULL;
    Node* next,*temp;
    for(Node* curr=head;curr!=NULL;){
        next=curr->next;
        curr->next=new Node(curr->val);
        curr->next->next=next;
        curr=next;
    }
    for(Node* curr=head;curr!=NULL;curr=curr->next->next){
        curr->next->random=curr->random!=NULL?curr->random->next:NULL;
    }
    Node* original=head,*copy=head->next;
    temp=copy;
    while(original && copy){
        original->next=original->next?original->next->next:NULL;
        copy->next=copy->next?copy->next->next:NULL;
        original=original->next;
        copy=copy->next;
    }
    return temp;
}
int main(){
    Node* head=NULL;
    int n,x,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    Node*res=copyRandomList(head);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
}