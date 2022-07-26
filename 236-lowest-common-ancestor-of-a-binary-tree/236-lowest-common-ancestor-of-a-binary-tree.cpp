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
     TreeNode*fun(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode*l=fun(root->left,p,q);
        TreeNode*r=fun(root->right,p,q);
        if(l!=NULL&&r!=NULL) return root;
        return l==NULL?r:l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root,p,q);
    }
};