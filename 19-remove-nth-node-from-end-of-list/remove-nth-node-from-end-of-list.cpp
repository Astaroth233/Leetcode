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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        ListNode* curr = head;
        while(curr)
        {
            curr = curr -> next;
            if(curr)
            {
                count ++;
            }
        }

        int need = count - n + 1;
        curr = head;
        int c = 1;
        ListNode* prev = NULL;
        while(c < need)
        {
            c++;
            prev = curr;
            curr = curr -> next;
        }
        if(prev)
        {
            prev -> next = curr -> next;
            return head;
        }
        else
        {
            curr = curr -> next;
            return curr;
        }
        
    }
};