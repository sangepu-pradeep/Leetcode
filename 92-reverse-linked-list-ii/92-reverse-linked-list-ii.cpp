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
    void reverse(ListNode*curr,ListNode*left=NULL,ListNode*right=NULL){
        ListNode*prev=right;
        while(curr!=right){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr; curr=temp;
        }
        if(left) left->next=prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*curr,*l,*r; 
        if(left==1){
            curr=head;l=NULL;
        }else{
            int ll=1; ListNode*d=head;
            while(ll!=left-1){
                d=d->next;ll++;
            }
            l=d; curr=l->next;
        }
        int rr=1; r=head;
        while(rr!=right){
            r=r->next;rr++;
        }
      
     reverse(curr,l,r->next);
         if(left==1) return r;
  
        return head;
    }
};