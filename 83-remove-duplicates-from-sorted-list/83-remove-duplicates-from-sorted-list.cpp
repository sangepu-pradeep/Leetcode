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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*d=new ListNode(-1);
        ListNode*f=NULL; ListNode*s=head;
        while(s){
             f=s;
            while(f&&f->val==s->val){
                f=f->next;
            }
            s->next=f;
            s=f;
        }
        return head;
    }
};