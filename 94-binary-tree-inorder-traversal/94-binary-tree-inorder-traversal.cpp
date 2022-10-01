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
vector<int>ans;
void fun(TreeNode*root){
    if(root==NULL) return;
    fun(root->left);
    ans.push_back(root->val);
    fun(root->right);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans={};
        fun(root);
        return ans;
    }
};