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
    int cnt=0;
    void fun(TreeNode*root,int mx){
        if(root==NULL) return ;
        mx=max(mx,root->val);
        if(mx<=root->val)cnt++;
        fun(root->left,mx);
        fun(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
       cnt=0; int mx=INT_MIN;
        fun(root,mx);
        return cnt;
    }
};