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
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==NULL) return res;
    queue<TreeNode*> q; 
    q.push(root);
    while(!q.empty()){
        vector<int> v;
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        res.push_back(v);
    }
    return res;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<vector<int>> res=levelOrder(root);
    for(auto x:res){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}