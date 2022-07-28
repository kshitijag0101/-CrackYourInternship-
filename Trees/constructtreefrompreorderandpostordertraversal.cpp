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
    TreeNode* construct(vector<int>& pre,int prei,int prej,vector<int> post,int posti,int postj){
        if(prei>prej) return NULL;
        TreeNode* root=new TreeNode(pre[prei]);
        if(prei==prej){
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        int ind=1;
        for(int i=1;i<=prej-prei;i++){
            if(pre[prei+i]==post[postj-1] && (i<2 || post[posti+i-2]==pre[prei+1])){
                ind=i;break;
            }
        }
        root->left = construct(pre, prei+1, prei+ind-1, post, posti, posti+ind-2);
        root->right = construct(pre, prei+ind, prej, post, posti+ind-1, postj-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};