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


    void fun(TreeNode*root,map<int,vector<pair<int,int>>>&mp, int d, int w){
        if(root==NULL) return ;
         mp[w].push_back({d,root->val});
        fun(root->left,mp,d+1,w-1);
        fun(root->right,mp,d+1,w+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,vector<pair<int,int>>>mp;
        fun(root,mp,0,0); vector<vector<int>>ans;
        for(auto a:mp){
           auto d=a.second; vector<int>temp;
            sort(d.begin(),d.end());
            for(auto t:d) temp.push_back(t.second);
            ans.push_back(temp);
        }
        return ans;
    }
};