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
    int fun(TreeNode*root,map<int,vector<int>>&mp){
       if(root==NULL) return 0;
         int t=max(fun(root->left,mp),fun(root->right,mp));
        mp[t].push_back(root->val);
        return t+1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
     map<int,vector<int>>mp;
        fun(root,mp);
        vector<vector<int>>ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
       return ans;
    }
};