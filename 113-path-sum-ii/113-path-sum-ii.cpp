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
    void fun(TreeNode*root,vector<int>&temp,int sum,int target,vector<vector<int>>&ans)
    {
        if(sum+root->val==target&&root->left==NULL&&root->right==NULL)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        if(root->left==NULL&&root->right==NULL) return ;
    
        if(root->left==NULL) { temp.push_back(root->val);return fun(root->right,temp,sum+root->val,target,ans);}
        
        if(root->right==NULL) { temp.push_back(root->val);return fun(root->left,temp,sum+root->val,target,ans);}
              temp.push_back(root->val);
           vector<int>p(temp);
         fun(root->left,temp,sum+root->val,target,ans);
            
        fun(root->right,p,sum+root->val,target,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;vector<int>temp;
         if(root==NULL) return {};
          fun(root,temp,0,sum,ans);
        return ans;
    }
};