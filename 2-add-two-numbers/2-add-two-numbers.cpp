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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long int a = 0,b=0;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
        
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carry = 0;
        
        while(c1 && c2){
            int x = c1->val+c2->val+carry;
            carry = 0;
            ListNode* tem = new ListNode(x%10);
            curr->next = tem;
            curr = curr->next;
            if(x>=10){
                carry = 1;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        while(c1){
            int x = c1->val+carry;
            carry = 0;
            ListNode* tem = new ListNode(x%10);
            curr->next = tem;
            curr = curr->next;
            if(x>=10){
                carry = 1;
            }
            c1 = c1->next;            
        }
        while(c2){
            int x = c2->val+carry;
            carry = 0;
            ListNode* tem = new ListNode(x%10);
            curr->next = tem;
            curr = curr->next;
            if(x>=10){
                carry = 1;
            }
            c2 = c2->next;            
        }        
        if(carry){
            ListNode* tem = new ListNode(carry);
            curr->next = tem;            
        }
        return head->next;
    }
};