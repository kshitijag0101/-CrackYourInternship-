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
bool checkval(TreeNode* root, TreeNode* subRoot){
    if(root==NULL && subRoot==NULL){
        return true;
    }
    else if(root && subRoot){
        if(root->val!=subRoot->val) return false;
        return checkval(root->left,subRoot->left) && checkval(root->right,subRoot->right);
    }
    else{
        return false;
    }
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(checkval(root,subRoot)){
        return true;
    }
    else{
        if(root==NULL) return false;
    }
    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}
int main(){
    TreeNode* root=new TreeNode(1);
    TreeNode* subRoot=new TreeNode(2);
    root->left=subRoot;
    root->right=new TreeNode(3);
    subRoot->left=new TreeNode(4);
    subRoot->right=new TreeNode(5);
    bool res=isSubtree(root,subRoot);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}