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
    ListNode*fun(ListNode*head){
        if(head==NULL) return NULL;
        ListNode*d=new ListNode(-1);
        d->next=head;
        ListNode*prev=NULL;ListNode*temp=head;
        while(temp){
            ListNode*t=temp->next;
            temp->next=prev;
              prev=temp;temp=t;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
      ListNode*f;ListNode*s;
        f=head;s=head;
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
       ListNode*temp= fun(s);
        ListNode*a=head;ListNode*b=temp;
        while(a&&b){
            if(a->val!=b->val){
                return 0;
            }
            a=a->next;b=b->next;
        }
        return 1;
    }
};