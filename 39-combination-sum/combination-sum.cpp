class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(candidates, target, ans, res, 0, 0);
        return res;
    }

    void helper(vector<int> &nums, int target, vector<int> &ans, vector<vector<int>> &res, int sum, int idx)
    {
        if(idx == nums.size())
        {
            if(sum == target)
            {
                res.push_back(ans);
            }
            return;
        }

        helper(nums, target, ans, res, sum, idx+1);
        if(nums[idx] + sum <= target)
        {
            ans.push_back(nums[idx]);
            sum = sum + nums[idx];
            helper(nums, target, ans, res, sum, idx);
            ans.pop_back();
            sum = sum - nums[idx];
        }


    }
};