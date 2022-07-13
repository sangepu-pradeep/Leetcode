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
 
  
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root); vector<vector<int>>ans;
        while(q.size()){
            int n=q.size();vector<int>temp;
            while(n--){
                auto a=q.front();q.pop(); temp.push_back(a->val);
                if(a->left) q.push(a->left);
                if(a->right)q.push(a->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};