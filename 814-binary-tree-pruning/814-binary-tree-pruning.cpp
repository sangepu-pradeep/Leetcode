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
    bool fun(TreeNode*root){
        if(root==NULL)  return 0;
        bool ans=0;
        if(root->val)ans=1;
        int l=fun(root->left);
        if(l==0) root->left=NULL;
       else ans=1;
        int r=fun(root->right);
        if(r==0) root->right=NULL;
        else ans=1;
        
        return ans;
    }
    TreeNode* pruneTree(TreeNode* root) {
       int b= fun(root);
        if(b==0) return NULL;
        return root;
    }
};