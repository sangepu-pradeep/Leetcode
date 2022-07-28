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
    pair<TreeNode*,TreeNode*> fun(TreeNode*root){
        if(root==NULL) return {NULL,NULL};
        auto a=fun(root->left);
        auto b=fun(root->right);
        root->left=NULL;
        TreeNode*temp=a.first==NULL?b.first:a.first;
        TreeNode*l=b.second==NULL?a.second:b.second;
     if(a.second)a.second->right=b.first;
        if(l==NULL) l=root;
        root->right=temp;
        return {root,l};
    }
    void flatten(TreeNode* root) {
        fun(root);
    }
};