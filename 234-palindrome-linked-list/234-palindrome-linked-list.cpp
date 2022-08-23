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
    ListNode *temp;
    bool helper(ListNode* head){
        if(head == NULL)   return true;
        
        bool flag = helper(head->next) && head->val == temp->val;
        temp = temp->next;
        
        return flag;
    }
    bool isPalindrome(ListNode* head) {
        temp = head;
        
        return helper(head);
    
    }
};