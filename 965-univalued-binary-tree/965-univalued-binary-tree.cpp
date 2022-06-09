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
    bool fun(TreeNode*root,int v){
        if(root==NULL) return 1;
        if(root->val==v&&fun(root->left,v)&&fun(root->right,v)) return 1;
        return 0;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return 1;
      int v=root->val;
        return fun(root,v);
    }
};