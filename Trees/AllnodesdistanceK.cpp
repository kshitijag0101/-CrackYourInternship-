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
void findParent(map<TreeNode*,TreeNode*>& mp,TreeNode* root){
    if(root==NULL) return;
    if(root->left!=NULL){
        mp[root->left]=root;
    }
    if(root->right!=NULL){
        mp[root->right]=root;
    }
    findParent(mp,root->left);
    findParent(mp,root->right);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> res;
    if(root==NULL) return res;
    map<TreeNode*,TreeNode*> mp;
    findParent(mp,root);
    set<TreeNode*> s;
    queue<TreeNode*> q;
    q.push(target);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp=q.front();
            q.pop();
            s.insert(temp);
            if(k==0){
                res.push_back(temp->val);
            }
            if(mp.find(temp)!=mp.end() && s.find(mp[temp])==s.end()){
                q.push(mp[temp]);
            }
            if(temp->left!=NULL && s.find(temp->left)==s.end()){
                q.push(temp->left);
            }
            if(temp->right!=NULL && s.find(temp->right)==s.end()){
                q.push(temp->right);
            }
        }
        k--;
        if(k<0) break;
    }
    return res;
}
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    int k=2;
    TreeNode* target=root->left;
    vector<int> res=distanceK(root,target,k);
    for(int x:res){
        cout<<x<<" ";
    }
}