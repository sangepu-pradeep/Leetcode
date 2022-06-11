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
ListNode* reverse(ListNode*curr, ListNode*prev=NULL){
    while(curr){
        ListNode*temp=curr->next;
        curr->next=prev;
         prev=curr;
        curr=temp;
    }
    return prev;
}
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*fast=head;ListNode*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        int ans=0; ListNode*h=head;
        while(slow){
            ans=max(ans,slow->val+h->val);
            h=h->next;slow=slow->next;
        }
        reverse(slow);
        return ans;
    }
};