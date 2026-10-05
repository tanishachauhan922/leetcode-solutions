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
    private:
     ListNode* reversell(ListNode* head,ListNode* tail){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=head;
        while(forward!=tail){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* curr=head;
        bool flag =false;
        ListNode* newhead=head;
        ListNode* prevtail=NULL;
        while(curr!=NULL){
            int p=1;
            ListNode* th=curr;
            while(p<=k && curr!=NULL){
                p++;
                curr=curr->next;
            }
            ListNode* revth=NULL;
            if(p>k){
           revth=reversell(th,curr);
            th->next = curr;
            }
            else revth=th;
            if( flag==false){
                newhead=revth;
                flag=true;
                }
                else prevtail->next=revth;
           // th->next=curr;
             prevtail=th;
        }
        return newhead;
    }
};