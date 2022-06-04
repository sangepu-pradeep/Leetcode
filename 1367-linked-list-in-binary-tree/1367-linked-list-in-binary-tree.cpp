/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool fun(ListNode*head, TreeNode*root){
        if(head==NULL) return 1;
        if(root==NULL) return 0;
        if(head->val!=root->val) return 0;
        return fun(head->next,root->left)||fun(head->next,root->right);
     
    }
    bool solve(ListNode*head,TreeNode*root){
        if(head==NULL) return 1;
        if(root==NULL) return 0;
        if(head->val==root->val&&fun(head,root)) return 1;
       return  solve(head,root->left)|| solve(head,root->right);
       
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
       return solve(head,root); 
    }
};