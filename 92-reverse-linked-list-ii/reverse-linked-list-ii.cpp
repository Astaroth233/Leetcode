class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = NULL;
        ListNode* r = NULL;
        ListNode* curr = head;
        ListNode* pl = NULL;
        ListNode* ar = NULL;
        ListNode* prev = NULL;
        int count = 0;

        while(curr && (l == NULL || r == NULL))
        {
            count++;

            if(count == left)
            {
                l = curr;
                pl = prev;
            }
            else if(count == right)
            {
                r = curr;
                ar = curr->next;
            }

            prev = curr;
            curr = curr->next;
        }

        if (!l || !r) return head;

        prev = NULL;
        curr = l;

        while(curr != ar)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // reconnect
        if (pl) {
            pl->next = prev;
        } else {
            head = prev;
        }

        l->next = ar;

        return head;
    }
};