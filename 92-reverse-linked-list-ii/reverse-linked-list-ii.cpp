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
     ListNode* reverseList(ListNode* head ) {
        if(head==NULL || head==NULL) return head;
        ListNode* curr=head;
        ListNode* forward=head;
        ListNode* backward=NULL;
        while(curr!=NULL && forward!=NULL){
            forward=curr->next;
            curr->next=backward;
            backward=curr;
            curr=forward;
        }
        return backward;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=new ListNode(-1);
        ListNode* dummy=temp;
        temp->next=head;
        int l=0,r=0;
        if(left==right)return head;
        while(temp!=NULL && l<left-1){
            temp=temp->next;
            l++;
        }
       ListNode* toconnect=temp;
      ListNode* revhead=temp->next;
        temp=revhead;
        while(temp!=NULL && l<right-1){
            temp=temp->next;
            l++;
        }
      ListNode* revtail=temp;
      ListNode* forw=NULL;
       if(revtail!=NULL) {forw=revtail->next;
        revtail->next=NULL;
       }
       ListNode* newhead= reverseList(revhead);
       temp=newhead;
      toconnect->next=newhead;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=forw;
      return dummy->next;
      
    }
};