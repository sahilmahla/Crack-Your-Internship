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
    int getDecimalValue(ListNode* head) {
        
        ListNode* c = head;
        int l = 0;
        while(c){
            c = c->next;
            l+=1;
        }
//cout<<l<<" ";
        l--;
        int k = 0;
        c = head;
        while(c){
            k = k + c->val*(pow(2,l));
//cout<<k<<"\n";
            l--;
            c=c->next;
        }
        
        return k;
    }
};