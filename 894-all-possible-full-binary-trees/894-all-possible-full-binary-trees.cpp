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
    vector<TreeNode*>fun( int n){
        if(n==0) return {};
        if(n==1) return {new TreeNode(0)};
        vector<TreeNode*>ans;
        for(int i=1;i<=n-1;i+=2){
           vector<TreeNode*>l=fun(i);
            vector<TreeNode*>r=fun(n-1-i);
            for(auto a:l){
                for(auto b:r){
                    TreeNode*temp=new TreeNode(0);
                    temp->left=a; temp->right=b;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        return fun(n);
    }
};