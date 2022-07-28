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
void DFS(TreeNode* root,string str,vector<string> &res){
    if(root->left==NULL && root->right==NULL){
        str=str+to_string(root->val);
        res.push_back(str);
        return;
    }
    str=str+to_string(root->val)+"->";
    if(root->left) DFS(root->left,str,res);
    if(root->right) DFS(root->right,str,res);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root==NULL) return res;
    DFS(root,"",res);
    return res;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<string> res=binaryTreePaths(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}