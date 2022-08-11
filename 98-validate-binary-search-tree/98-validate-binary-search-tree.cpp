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
     int prev;
    void fun(TreeNode*root,vector<int>&temp)
    {  if(root==NULL) return;
     fun(root->left,temp);
        temp.push_back(root->val);
        fun(root->right,temp);
     
       
    }
    bool isValidBST(TreeNode* root) {
        prev=INT_MIN;vector<int>temp;
         fun(root,temp);
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]<=temp[i-1]) return false;
        }
        return true;
    }
};