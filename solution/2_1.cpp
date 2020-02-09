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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int flag = 0;
        ListNode* output;
        ListNode* node;
        ListNode* tmp_node;
        
        int tmp = l1->val + l2->val + flag;
        if (tmp < 10)
        {
            tmp_node = new ListNode(tmp);
            flag = 0;
        }
        else
        {
            tmp_node = new ListNode(tmp%10);
            flag = 1;
        }
            
        output = tmp_node;
        node = output;
        l1 = l1->next;
        l2 = l2->next;
        
        while ((l1 != NULL)&&(l2 != NULL))
        {
            int tmp = l1->val + l2->val + flag;
            if (tmp < 10)
            {
                tmp_node = new ListNode(tmp);
                flag = 0;
            }
            else
            {
                tmp_node = new ListNode(tmp%10);
                flag = 1;
            }
            
            node->next = tmp_node;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* left;
        
        if (l1 == NULL)
            left = l2;
        else
            left = l1;
        
        while(left != NULL)
        {
            int tmp = left->val + flag;
            if (tmp < 10)
            {
                tmp_node = new ListNode(tmp);
                flag = 0;
            }
            else
            {
                tmp_node = new ListNode(tmp%10);
                flag = 1;
            }
            node->next = tmp_node;
            node = node->next;
            left = left->next;
        }
        
        if (flag == 1)
        {
             node->next = new ListNode(1);
        }
        
        return output;
    }
};
