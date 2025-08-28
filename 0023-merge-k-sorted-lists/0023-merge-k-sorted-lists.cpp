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
    struct compare{
        bool operator()(const pair<int,ListNode*>&a, const pair<int, ListNode*> &b){
            return a.first>b.first;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, compare> minheap;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]) minheap.push({lists[i]->val, lists[i]});
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(!minheap.empty()){
            auto it= minheap.top();
            minheap.pop();

            ListNode* minval= it.second;
            if(minval->next) minheap.push({minval->next->val,minval->next});
            temp->next= minval;
            temp=temp->next;
        }
        return dummy->next;
    }
};
/*
ListNode* merge2(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* t1= list1;
        ListNode* t2= list2;
        ListNode* temp=dummy;

        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                temp->next= t1;
                t1= t1->next;
            }
            else{
                temp->next= t2;
                t2= t2->next;
            }
            temp= temp->next;
        }
        if(t1) temp->next= t1;
        if(t2) temp->next= t2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* head= lists[0];
        for(int i=1; i<lists.size(); i++){
            head= merge2(head, lists[i]);
        }
        return head;
    }
*/