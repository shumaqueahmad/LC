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
        // using prev, temp and front to track
        // front is used to store locn to move temp to
        // prev tracks the prev node temp need to connect
        // 1->2->3->
        //p   c  f
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode*prev= NULL;
        ListNode* front= head->next;

        while(temp!=NULL){
            front= temp->next;
            temp->next= prev;
            prev=temp;
            temp= front; 
        }

        return prev;
    }
};