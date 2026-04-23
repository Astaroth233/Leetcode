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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second = slow -> next;
        slow -> next = NULL;

        ListNode* prev = NULL;

        while(second != NULL)
        {
            ListNode* nxt = second -> next;
            second -> next = prev;
            prev = second;
            second = nxt;
        }

        ListNode* f = head;
        ListNode* s = prev;

        while(s)
        {
            ListNode* temp1 = f -> next;
            ListNode* temp2 = s -> next;

            f -> next = s;
            s -> next = temp1;

            f = temp1;
            s = temp2;
        }


    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        prev = head;
        return prev;
    }
};