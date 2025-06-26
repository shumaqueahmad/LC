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
    ListNode * helper(ListNode *head, ListNode *slow){
        ListNode *temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head ==NULL) return NULL;
        ListNode * slow= head;
        ListNode * fast= head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return helper(head,slow);
            }
        }
        return NULL;
    }
};
/*
if(head==NULL) return NULL;
        int pos=0;
        unordered_map<ListNode *, int> mp;
        ListNode * temp=head;

        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp]= pos;
            pos++;
            temp=temp->next;
        }
*/