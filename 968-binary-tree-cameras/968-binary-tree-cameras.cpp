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
    int fun(TreeNode*root, int prev, int pres,map<pair<TreeNode*,pair<int,int>>,int>&mp){
        if(root==NULL) return 0;
        if(mp.count({root,{prev,pres}})) return mp[{root,{prev,pres}}];
        
        int ans=INT_MAX;
       if(prev==0){
     ans=min(ans,1+fun(root->left,1,1,mp)+fun(root->right,1,1,mp));
if(pres==0&&root->left) ans=min(ans,fun(root->left,0,1,mp)+fun(root->right,1,0,mp));

    if(pres==0&&root->right) ans=min(ans,fun(root->left,0,1,mp)+fun(root->right,1,0,mp));     
       }
        if(prev==1&&pres==0){
         ans=min(ans,1+fun(root->left,1,1,mp)+fun(root->right,1,1,mp)); 
      if(root->left)  ans=min(ans,fun(root->left,0,1,mp)+fun(root->right,1,0,mp));    if(root->right)  ans=min(ans,fun(root->right,0,1,mp)+fun(root->left,1,0,mp));
        }
        if(prev==1&&pres==1){
      ans=min(ans,1+fun(root->left,1,1,mp)+fun(root->right,1,1,mp));
    ans=min(ans,fun(root->left,1,0,mp)+fun(root->right,1,0,mp));
        }
        return mp[{root,{prev,pres}}]=ans;
    }
    int minCameraCover(TreeNode* root) {
    map<pair<TreeNode*,pair<int,int>>,int>mp;
      return fun(root,1,0,mp);  
    }
};