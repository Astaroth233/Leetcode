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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> sol;
        helper(root, sum, sol, targetSum);
        return res;
    }

    void helper(TreeNode* root, int sum, vector<int> &sol, int target)
    {
        if(root == NULL)
        {
            return;
        }
        sum += root -> val;
        sol.push_back(root->val);

        if(root -> left == NULL && root -> right == NULL)
        {
            if(sum == target)
            {
                res.push_back(sol);
            }
        }
        else
        {
            helper(root -> left, sum, sol, target);
            helper(root -> right, sum, sol, target);
        }
        sol.pop_back();
    }
};