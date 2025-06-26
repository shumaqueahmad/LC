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
        ListNode* front= head->next;


        while(temp!=NULL){
            front= temp->next;
            temp->next=prev;
            prev= temp;
            temp= front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow= head;
        ListNode* fast= head;

        while(fast->next!=NULL && fast->next->next!=NULL){ // o(n/2)
            slow= slow->next;
            fast= fast->next->next;
        }

        ListNode* head2= reverse(slow->next); //o(n/2)

        ListNode* t1= head;
        ListNode* t2= head2;

        while(t2!=NULL){ //o(n/2)
            if(t1->val != t2->val){
                reverse(head2);
                return false;
            }
            t1= t1->next;
            t2= t2->next;

        }

        reverse(head2); // reversing so that not to alter te data : o(n/2)
        return true;


    }
};