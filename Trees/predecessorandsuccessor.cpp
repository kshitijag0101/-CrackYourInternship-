#include <iostream>
using namespace std;
struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	Node(int x){
        key = x;
        left = NULL;
        right = NULL;
	}
};
int key=0;
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if(root==NULL) return;
    if(root->key==key){
        if(root->left!=NULL){
            Node* temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            pre=temp;
        }
        if(root->right!=NULL){
            Node* temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            suc=temp;
        }
    }
    else if(root->key<key){
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else{
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
}
void insert(struct Node *root,int n1,int n2,char lr){
    if(root==NULL) return;
    if(root->key==n1){
        switch(lr){
            case 'L': root->left=new Node(n2);break;
            case 'R': root->right=new Node(n2);break;
        }
    }
    else{
        insert(root->left,n1,n2,lr);
        insert(root->right,n1,n2,lr);
    }
}
int main(){
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else{
            insert(root,n1,n2,lr);
        }
    }
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";
	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
