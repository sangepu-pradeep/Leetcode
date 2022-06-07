/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*tempa=headA; int la=0;
        while(tempa){
            tempa=tempa->next;la++;
        }
        ListNode*tempb=headB; int lb=0;
        while(tempb){
            tempb=tempb->next;lb++;
        }
                tempa=headA; tempb=headB;
        if(la<=lb) {swap(la,lb);swap(tempa,tempb);}
        int diff=la-lb;

        //cout<<diff;
       // cout<<tempa->val;
        while(diff--){
            tempa=tempa->next;
        }
        while(tempb!=tempa){
            if(tempa==NULL||tempb==NULL) return NULL;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        return tempb;
    }
};