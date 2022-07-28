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
TreeNode* insert(vector<int>& nums,int l,int h){
    if(l>h) return NULL;
    int mid=(l+h)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=insert(nums,l,mid-1);
    root->right=insert(nums,mid+1,h);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return insert(nums,0,nums.size()-1);
}
void printTree(TreeNode* root) {
    queue<TreeNode*> q; 
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    TreeNode* root=NULL;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    root=sortedArrayToBST(nums);
    printTree(root);
}