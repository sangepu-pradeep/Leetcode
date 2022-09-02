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
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*>q;
        q.push(root);vector<double>ans;
        while(q.size()){
            int sz=q.size();double sum=0; int cnt=0;
            while(sz--){
                TreeNode*temp=q.front(); q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right) q.push(temp->right);
                sum+=temp->val;cnt++;
            }
            double p=(double)sum/cnt;
            ans.push_back(p);
        }
        return ans;
    }
    
};