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
    int idx = 0;
    unordered_map<int, int> in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            in[inorder[i]] = i;
        }
        return func(preorder, 0, inorder.size()-1);
    }

    TreeNode* func(vector<int> &pre, int low, int high)
    {
        if(low > high)
        {
            return NULL;
        }

        TreeNode* node = new TreeNode(pre[idx]);
        idx++;

        int id = in[node -> val];
        node -> left = func(pre, low, id - 1);
        node -> right = func(pre, id + 1, high);
        return node;
    }
};