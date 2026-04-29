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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
        {
            return NULL;
        }

        if(k == 0)
        {
            return head;
        }

        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr)
        {
            count ++;
            prev = curr;
            curr = curr -> next;
        }

        if(count == 1){
            return head;
        }

        if(k % count == 0)
        {
            return head;
        }

        int ans = count - (k % count);

        int i = 1;
        curr = head;
        while(i < ans)
        {
            i ++;
            curr = curr -> next;
        }

        ListNode* nxt = curr -> next;
        curr -> next = NULL;
        prev -> next = head;

        head = nxt;
        return head;
    }
};