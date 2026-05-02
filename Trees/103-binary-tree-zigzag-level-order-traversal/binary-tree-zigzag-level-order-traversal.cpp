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
        bool rev = true;

        vector<vector<int>> res;

        if(root == NULL)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int lvlSize = q.size();
            vector<int> temp;

            while(lvlSize --)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node -> val);
                
                if(node -> left)
                {
                    q.push(node -> left);
                }

                if(node -> right)
                {
                    q.push(node -> right);
                }
            }
            if(!rev)
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
            else
            {
                res.push_back(temp);
            }
            rev = !rev;
        }
        return res;
    }
};