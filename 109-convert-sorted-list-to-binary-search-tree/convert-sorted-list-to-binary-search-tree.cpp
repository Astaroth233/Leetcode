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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ll;
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr = head;
        while(curr)
        {
            ll.push_back(curr -> val);
            curr = curr -> next;
        }
        return func(ll, 0, ll.size()-1);
    }

    TreeNode* func(vector<int> ll, int low, int high)
    {
        if(low > high)
        {
            return NULL;
        }
        int mid = low + (high - low) / 2;
        TreeNode* node = new TreeNode(ll[mid]);

        node -> left = func(ll, low, mid - 1);
        node -> right = func(ll, mid + 1, high);
        return node;
    }
};