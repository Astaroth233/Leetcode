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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        bool rev = false;

        if(root == NULL)
        {
            return res;
        }
        q.push(root);
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp(s);
            int idx = 0;

            while(s--)
            {
                TreeNode* t = q.front();
                q.pop();
                temp[idx++] = t -> val;

                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            if(rev)
            {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                rev = false;
            }
            else
            {
                res.push_back(temp);
                rev = true;
            }

            
        }
        return res;
    }
};