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
    ListNode* reverseList(ListNode* head) {
        ListNode*d=head;
       ListNode*f=NULL;ListNode*s=head;
        while(s){
            ListNode*temp=s->next;
         s->next=f;
            f=s;s=temp;
        }
        return f;
    }
};