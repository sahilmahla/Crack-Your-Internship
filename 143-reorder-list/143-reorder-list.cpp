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
void reorderList(ListNode* head) {
        //1.find middle node
        ListNode *slow=head, *fast=head;
        
        while(fast and fast->next) 
            slow=slow->next, fast=fast->next->next;
           
        //2.from middle reverse the list
        ListNode *prev=NULL, *curr=slow, *nextNode=NULL;
        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }//prev will be pointing to the last node
        
        //3.start linking alternating nodes
        ListNode* temp, *first=head, *last=prev;
        while(last->next){
            temp = last->next; 
            last->next = first->next;
            first ->next = last;
            last = temp;
            first = first->next->next;
        }
        
    }
};