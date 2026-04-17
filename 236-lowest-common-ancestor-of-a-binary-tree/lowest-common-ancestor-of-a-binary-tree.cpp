/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        int h = helper(root, p, q, ans);
        return ans;
    }

    int helper(TreeNode* &root, TreeNode* &p, TreeNode* &q, TreeNode* &ans)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = helper(root->left, p, q, ans);
        int right = helper(root->right, p, q, ans);
        int self = 0;

        if(root == p || root == q)
        {
            self = 1;
        }

        int total = left + right + self;

        if(total == 2 && ans == NULL)
        {
            ans = root;
        }
        return total;
    }
};