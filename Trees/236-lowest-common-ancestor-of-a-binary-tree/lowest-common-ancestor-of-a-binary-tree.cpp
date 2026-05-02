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
    TreeNode* ans = NULL;
    int c = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lcaHelper(root, p, q, c);
        return ans;
    }

    int lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q, int &c)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = lcaHelper(root -> left, p, q, c);
        int right = lcaHelper(root -> right, p, q, c);
        int self = 0;
        if(root == p || root == q)
        {
            self = 1;
        }

        int total = left + right + self;

        if((total == 2 && c < 2)|| ans == NULL)
        {
            ans = root;
            c ++;
        }
        return total;
    }
};