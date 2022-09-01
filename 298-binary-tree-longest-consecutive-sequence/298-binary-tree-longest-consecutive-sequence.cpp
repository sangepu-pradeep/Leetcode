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
    int fun(TreeNode*root){
        if(root==NULL)return 0;
       auto l=fun(root->left);
        auto r=fun(root->right);
        int ans=1;
        if(root->left){
            int p=root->left->val;
            if(p==root->val+1) ans=max(ans,1+l);
        }
        if(root->right){
            int q=root->right->val;
            if(q==root->val+1)ans=max(ans,1+r);
        }
        cnt=max(ans,cnt);
        return ans;
        
    }
    int longestConsecutive(TreeNode* root) {
        cnt=0;
        fun(root);
        return cnt;
    }
};