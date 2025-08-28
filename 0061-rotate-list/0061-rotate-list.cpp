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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        // find last node
        int len=1;
        ListNode* lastnode=head;
        while(lastnode->next!=NULL){
            lastnode= lastnode->next;
            len++;
        }
        
        if(k%len==0) return head;
        k= k%len;
        lastnode->next= head;
        // find len-kth node from start

        ListNode* newtail=head;
        
        for(int i=1 ;i<len-k; i++){
            newtail= newtail->next;
        }

        head= newtail->next;
        newtail->next=NULL;

        return head;
    }
};