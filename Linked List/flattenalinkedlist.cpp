#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
struct mycomp{
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
void flatten(Node* root){
    priority_queue<Node*,vector<Node*>,mycomp> p;
    while(root!=NULL){
        p.push(root);
        root=root->next;
    }
    while(!p.empty()){
        auto k=p.top();
        p.pop();
        cout<<k->data<<" ";
        if(k->bottom) p.push(k->bottom);
    }
}
int main(){
    Node* head=new Node(5);
    auto temp=head;
    auto bt=head;
    bt->bottom=new Node(7);
    bt->bottom->bottom=new Node(8);
    bt->bottom->bottom->bottom=new Node(30);
    temp->next=new Node(10);
    temp=temp->next;
    bt=temp;
    bt->bottom=new Node(20);
    temp->next=new Node(19);
    temp=temp->next;
    bt=temp;
    bt->bottom=new Node(22);
    bt->bottom->bottom=new Node(50);
    temp->next=new Node(28);
    temp=temp->next;
    bt=temp;
    bt->bottom=new Node(35);
    bt->bottom->bottom=new Node(40);
    bt->bottom->bottom->bottom=new Node(45);
    flatten(head);
    cout << endl;
}