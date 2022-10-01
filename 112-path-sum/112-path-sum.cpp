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
    bool fun(TreeNode*root, int sum, int target){
        if(root==NULL) return 0;
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL&&sum==target) return 1;
        return fun(root->left,sum,target)||fun(root->right,sum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         return fun(root,0,targetSum);
    }
};