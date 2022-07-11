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

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        while(q.size()){
            int n=q.size();
            while(n--){
               auto temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                if(n==0) ans.push_back(temp->val);
            }
        }
        return ans;
    }
};