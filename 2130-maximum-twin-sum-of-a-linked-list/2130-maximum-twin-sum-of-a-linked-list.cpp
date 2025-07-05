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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* front= temp->next;
        while(temp!=NULL){
            front= temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*slow= head;
        ListNode*fast= head;

        while(fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        //reached M1
        ListNode* head2= reverse(slow->next);
        ListNode* temp=head;
        int maxi=INT_MIN;
        while(head2!=NULL){
            int val= temp->val+ head2->val;
            maxi= max(maxi,val);
            head2=head2->next;
            temp=temp->next;
        }

        return maxi;
    }
};