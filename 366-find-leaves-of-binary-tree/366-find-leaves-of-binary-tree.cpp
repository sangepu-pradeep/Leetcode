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
    void fun(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&mp,unordered_map<TreeNode*,int>&vis,TreeNode*prev){
        if(root==NULL) return;
        mp[root]=prev;
        int p=0;
        if(root->left) p++;
        if(root->right) p++;
         vis[root]=p;
        fun(root->right,mp,vis,root);
        fun(root->left,mp,vis,root);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        // priority_queue<pair<int,TreeNode*>,vector<pair<int,TreeNode*>>,greater<pair<int,TreeNode*>>>pq;
        unordered_map<TreeNode*,int>vis;
        unordered_map<TreeNode*,TreeNode*>mp; vector<vector<int>>ans;
        if(root==NULL) return {};
        fun(root,mp,vis,NULL);
        while(vis.size()){
            vector<TreeNode*>temp;
           for(auto a:vis){
           if(a.second==0&&a.first==root) {ans.push_back({root->val});
                                           return ans;}
               
           if(a.second==0){
               temp.push_back(a.first);
           }
          } 
            vector<int>y;
          for(auto a:temp){
             // cout<<a->val<<endl;
              y.push_back(a->val);
              vis[mp[a]]--; vis[a]--;
          }  
            ans.push_back(y);
        }
        return ans;
       
    }
};