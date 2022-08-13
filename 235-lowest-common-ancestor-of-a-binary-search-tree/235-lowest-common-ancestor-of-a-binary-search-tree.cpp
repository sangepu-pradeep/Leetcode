/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode*ans;
    bool fun(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL)return 0;
        int t=0;
        if(root==p||root==q)t++;
        t+=fun(root->left,p,q);
        t+=fun(root->right,p,q);
        if(t==2)ans=root;
        return t>0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=NULL;
        fun(root,p,q);
        return ans;
    }
};