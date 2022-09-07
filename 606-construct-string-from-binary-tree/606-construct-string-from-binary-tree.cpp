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
    string fun(TreeNode*root){
        if(root==NULL) return "";
        string ans;
        auto a=fun(root->left);
        auto b=fun(root->right);
        int p=root->val;
        string y=to_string(p);
        ans+=y;
        if(a.size()==0&&b.size()==0) return ans;
           ans+="("+a+")";
         if(b.size()) ans+="("+b+")";
        return ans;
    }
    string tree2str(TreeNode* root) {
        return fun(root);
    }
};