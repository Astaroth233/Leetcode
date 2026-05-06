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
        
        vector<int> diary;
        helper(root, targetSum, diary);
        return res;
    }

    void helper(TreeNode* root, int targetSum, vector<int> &diary)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            if(targetSum == root -> val)
            {
                diary.push_back(root->val);
                res.push_back(diary);
                diary.pop_back();
            }
            return;
        }

        int remaining = targetSum - root->val;
        diary.push_back(root->val);
        helper(root->left, remaining, diary);
        helper(root->right, remaining, diary);
        diary.pop_back();
    }
};