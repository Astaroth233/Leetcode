class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, path, 0);
        return res;  
    }

    void dfs(vector<int> &nums, vector<int> &path, int idx)
    {
        res.push_back(path);

        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i] == nums[i-1])
            {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};