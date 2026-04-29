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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;

        while(temp)
        {
            ListNode* KNode = findKthNode(temp, k);
            if(!KNode)
            {
                if(prevNode != NULL)
                {
                    prevNode -> next = temp;
                }
                break;
            }
            nextNode = KNode -> next;
            KNode -> next = NULL;
            reverse(temp);

            if(temp == head)
            {
                head = KNode;
            }
            else
            {
                prevNode -> next = KNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }

    ListNode* reverse(ListNode* temp)
    {
        ListNode* prev = NULL;
        ListNode* curr = temp;

        while(curr)
        {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k)
    {
        int idx = 0;
        while(idx != k - 1 && temp)
        {
            temp = temp -> next;
            idx ++;
        }
        return temp == NULL ? NULL : temp;
    }
};