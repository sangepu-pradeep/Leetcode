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
    TreeNode*fun(int st, int e,vector<int>&nums){
        if(st>e)return NULL;
       if(st==e) return new TreeNode(nums[st]);
        int p=(st+e)/2;
        TreeNode*root=new TreeNode(nums[p]);
        root->left=fun(st,p-1,nums);
        root->right=fun(p+1,e,nums);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return fun(0,n-1,nums);
    }
};