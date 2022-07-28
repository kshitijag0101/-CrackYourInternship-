#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool check(TreeNode* temp1,TreeNode* temp2){
    if(temp1==NULL || temp2==NULL){
        return temp1==temp2;
    }
    bool l=check(temp1->left,temp2->right);
    if(temp1->val!=temp2->val){
        return false;
    }
    bool r=check(temp1->right,temp2->left);
    return l&&r;
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL) return NULL;
    TreeNode* temp1=root->left;
    TreeNode* temp2=root->right;
    return check(temp1,temp2);
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(4);
    bool res=isSymmetric(root);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}