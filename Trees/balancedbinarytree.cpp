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
int count;
void solve(TreeNode* root, int targetSum,long long sum){
    if(root==NULL) return;
    sum+=root->val;
    if(sum==targetSum){
        count++;
    }
    solve(root->left,targetSum,sum);
    solve(root->right,targetSum,sum);
}
int pathSum(TreeNode* root, int targetSum) {
    if(root==NULL) return count;
    solve(root,targetSum,0);
    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);
    return count;
}
int main(){
    count=0;
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(-3);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(2);
    root->right->right=new TreeNode(11);
    root->left->left->left=new TreeNode(3);
    root->left->left->right=new TreeNode(-2);
    root->left->right->right=new TreeNode(1);
    int targetSum=8;
    int res=pathSum(root,targetSum);
    cout<<res<<endl;
}