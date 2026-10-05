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
    ListNode* getmid(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        delete(dummy);
        return slow;
    }
    //mereg
    ListNode* merge(ListNode* head1,ListNode* head2){
       if(head1==NULL) return head2;
       if(head2==NULL) return head1;
       ListNode* temp=new ListNode(-1);
       ListNode* newhead=temp;
       ListNode* l1=head1;
       ListNode* l2=head2;
      while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){
            temp->next=l1;
        l1=l1->next;
      }
      else{
        temp->next=l2;
        l2=l2->next;
      }
      temp=temp->next;
    }
    while(l1){
        temp->next=l1;
        l1=l1->next;
        temp=temp->next;
    }
    while(l2){
        temp->next=l2;
        l2=l2->next;
        temp=temp->next;
    }
    
    return newhead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=getmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* leftpart=sortList(left);
        ListNode* rightpart=sortList(right);
      ListNode* newhead= merge(leftpart,rightpart);
      return newhead;
    }
};