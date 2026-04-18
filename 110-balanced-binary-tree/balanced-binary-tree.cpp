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
    bool failed = false;
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }

        int h = height(root);
        return (failed == true) ? false : true;
    }

    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return -1;
        }

        int left = height(root -> left);
        int right = height(root -> right);
        int diff = abs(right - left);
        if(diff > 1)
        {
            failed = true;
        }
        return max(left,right) + 1;
    }
};