/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int width=0;
        if(root==NULL) return width;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int ind=q.front().second;
            int start,end;
            for(int i=0;i<n;i++){
                long long curr=q.front().second-ind;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0) start=curr;
                if(i==n-1) end=curr;
                if(temp->left) q.push({temp->left,(curr*2)+1});
                if(temp->right) q.push({temp->right,(curr*2)+2});
            }
            width=max(width,end-start+1);
        }
        return width;
    }
};