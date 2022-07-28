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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,vector<int>>> mp;
        vector<vector<int>> res;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(root==NULL) return res;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int ind=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mp[ind][level].push_back(temp->val);
            if(temp->left) q.push({temp->left,{ind-1,level+1}});
            if(temp->right) q.push({temp->right,{ind+1,level+1}});
        }
        for(auto x:mp){
            vector<int> v;
            for(auto y:x.second){
                sort(y.second.begin(),y.second.end());
                for(auto k:y.second){
                    v.push_back(k);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};