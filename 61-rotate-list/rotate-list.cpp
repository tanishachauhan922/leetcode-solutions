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
    int findl(ListNode* head){
        ListNode* temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL || k==0) return head;
        int len=findl(head);
        k=k%len;
        if(k==0) return head;
        int d=len-k;
       
            ListNode* temp=head;    
            int cnt=1;
            while(temp!=NULL && cnt<d){
                temp=temp->next;
                cnt++;
        }
        ListNode* cut=temp->next;
        ListNode* newhead=temp->next;
        temp->next=NULL;
        while(cut->next!=NULL){
            cut=cut->next;
        }
        cut->next=head;
          return newhead;
       
       
    }
};