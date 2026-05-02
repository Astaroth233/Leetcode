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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == NULL)
        {
            return false;
        }

        if(isSameTree(root, subRoot))
        {
            return true;
        }
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* sroot)
    {
        if(!root && !sroot)
        {
            return true;
        }
        if(!root || !sroot)
        {
            return false;
        }
        if(root -> val != sroot -> val)
        {
            return false;
        }
        bool r1 = isSameTree(root -> left, sroot -> left);
        bool r2 = isSameTree(root -> right, sroot -> right);

        return r1 && r2;
    }
};