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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1,*ptr1 = list1,*head2 = list2,*ptr2 = list2;
        
        ListNode* nh = new ListNode(-1);
        ListNode* p = nh;
                
        while(ptr1 && ptr2){
            if(ptr1->val > ptr2->val){
                p->next =  ptr2;
                p = p->next;
                ptr2 = ptr2->next;                
            }else{
                p->next =  ptr1;
                p = p->next;
                ptr1 = ptr1->next;                  
            }
        }
        
        while(ptr1){
                p->next =  ptr1;
                p = p->next;
                ptr1 = ptr1->next;              
        }
        while(ptr2){
                p->next =  ptr2;
                p = p->next;
                ptr2 = ptr2->next;      
        }
        
        return nh->next;
        
    }
};