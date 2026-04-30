class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> used(nums.size(), false);
        permhelp(nums, ans, res, used);
        return res;
    }

    void permhelp(vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, vector<bool> &used)
    {
        if(ans.size() == nums.size())
        {
            res.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i] = true;
            ans.push_back(nums[i]);
            permhelp(nums, ans, res, used);
            ans.pop_back();
            used[i] = false;
        }
    }
};