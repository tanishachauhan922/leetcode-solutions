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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head==NULL) return head;
         ListNode* dummy= new ListNode(-1);
         dummy->next=head;
         ListNode* slow=dummy;
         ListNode* fast=dummy;
         int cnt=0;
         while(fast->next!=NULL && cnt<n){
             fast=fast->next;
             cnt++;
               }
               if(cnt<n)return NULL;
               while(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
               }
               ListNode* todel=slow->next;
               ListNode* forw=todel->next;
               slow->next=forw;
               todel->next=NULL;
               delete(todel);
               return dummy->next;
    }
};