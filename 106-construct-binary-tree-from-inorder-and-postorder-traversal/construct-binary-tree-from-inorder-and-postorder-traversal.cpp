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
    unordered_map<int, int> m;
    int idx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }
        idx = postorder.size() - 1;
        return func(postorder, 0, inorder.size()-1);
    }


    TreeNode* func(vector<int> &postorder, int low, int high)
    {
        if(low > high)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[idx--]);

        int id = m[node -> val];
        node -> right = func(postorder,id+1, high);
        node -> left = func(postorder, low, id-1);
        
        return node;
    }
    
};