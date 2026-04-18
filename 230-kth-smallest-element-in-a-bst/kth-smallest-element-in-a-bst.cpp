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
    stack<TreeNode*> st;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        int idx = 0;
        while(node)
        {
            st.push(node);
            node = node -> left;
        }

        while(!st.empty())
        {
            TreeNode* small = st.top();
            st.pop();
            if(idx == k-1)
            {
                return small -> val;
            }

            TreeNode* rightchild = small -> right;
            while(rightchild)
            {
                st.push(rightchild);
                rightchild = rightchild -> left;
            }
            idx ++;
        }
        return -1;

    }
};