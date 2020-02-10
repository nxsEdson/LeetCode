/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* sub_top = head;
        ListNode* sub_bottom = head;
        
        for(int i = 0; i < n-1; i++)
        {
            sub_bottom = sub_bottom->next;
        }
        
        if (sub_bottom->next == NULL)
            return head->next;
        
        sub_bottom = sub_bottom->next;
        
        while(sub_bottom->next != NULL)
        {
            sub_bottom = sub_bottom->next; 
            sub_top = sub_top->next;
        }
        
        sub_top->next = sub_top->next->next;
        
        return head;
    }
};
