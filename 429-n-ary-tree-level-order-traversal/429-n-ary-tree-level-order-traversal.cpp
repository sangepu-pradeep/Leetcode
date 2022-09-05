/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        queue<Node*>q;
        q.push(root); vector<vector<int>>ans;
        while(q.size()){
            int sz=q.size();vector<int>t;
            while(sz--){
                Node*temp=q.front();
                q.pop();
                for(Node*a:temp->children){
                    q.push(a);
                }
                  t.push_back(temp->val);
            }
            ans.push_back(t);
        }
        return ans;
    }
};