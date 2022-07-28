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
void inorder(TreeNode* root,vector<int>& v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
bool isValidBST(TreeNode* root) {
    vector<int> v;
    inorder(root,v);
    for(int i=1;i<v.size();i++){
        if(v[i-1]>=v[i]){
            return false;
        }
    }
    return true;
}
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    bool res=isValidBST(root);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}