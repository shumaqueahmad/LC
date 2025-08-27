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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left== right) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp= dummy; 
        //marking just prev to left
        for(int i=1; i<left; i++){
            temp= temp->next;
        }

        ListNode* curr= temp->next;
        ListNode* newtail= curr;
        ListNode* back=NULL;
        ListNode* front= NULL;

        for(int i=0; i<right-left+1; i++){
            front= curr->next;
            curr->next= back;
            back=curr;
            curr=front;
            //new head will be back pointer
        }

        temp->next= back;
        newtail->next= curr;

        return head;
    }
};