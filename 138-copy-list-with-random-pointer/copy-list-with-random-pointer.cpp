/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp!=NULL){
            Node* newnode= new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        //now do clone
        temp=head;
        Node* newhead=mp[head];
        while(temp!=NULL){
            mp[temp]->next=mp[temp->next];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return newhead;
    }
};