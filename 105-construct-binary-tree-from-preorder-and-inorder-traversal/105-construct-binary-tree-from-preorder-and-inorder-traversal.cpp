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
    TreeNode* fun(vector<int>&pre,vector<int>&in, int &p, int l, int h){
        if(p==pre.size()) return NULL;
       if(l>h) return NULL;
       // if(l==h) return new TreeNode(in[l]);
        TreeNode*ans=new TreeNode(pre[p]);
        for(int i=l;i<=h;i++){
            if(pre[p]==in[i]){
                p++;
                ans->left=fun(pre,in,p,l,i-1);
                ans->right=fun(pre,in,p,i+1,h);
                break;
            }
        }
        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int p=0;
       return fun(preorder,inorder,p,0,n-1); 
    }
};