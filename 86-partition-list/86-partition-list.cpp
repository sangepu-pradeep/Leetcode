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
    ListNode* partition(ListNode* head, int x) {
        ListNode*d=new ListNode(-1);
        ListNode*temp=d;
        ListNode*n=new ListNode(-1);
        ListNode*t=n; ListNode*v=new ListNode(-1); ListNode*xx=v;
        ListNode*s=head;
        while(s){
            ListNode*nxt=s->next;
            if(s->val<x){
                temp->next=s;
                temp=temp->next; temp->next=NULL;
            }else if(s->val>=x){
               t->next=s;
                t=t->next;t->next=NULL;
            }
            s=nxt;
        
        }
       
  
         temp->next=n->next;
        return d->next;
    }
};