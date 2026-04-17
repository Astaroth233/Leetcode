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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool val = false;
        if(root == NULL && subRoot == NULL)
        {
            return true;
        }
        if(root == NULL || subRoot == NULL)
        {
            return false;
        }
        if(root -> val == subRoot -> val)
        {
            val = sameTree(root, subRoot);
        }

        bool r1 = isSubtree(root -> left, subRoot);
        bool r2 = isSubtree(root -> right, subRoot);
        if(r1 || r2 || val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool sameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }

        if(p == NULL || q == NULL)
        {
            return false;
        }

        if(p->val != q->val)
        {
            return false;
        }

        bool r1 = sameTree(p->left, q->left);
        bool r2 = sameTree(p->right, q->right);

        if(r1 && r2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};