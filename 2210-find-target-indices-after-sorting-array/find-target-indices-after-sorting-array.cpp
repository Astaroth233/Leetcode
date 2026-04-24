class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first = bs(nums, target, true);
        int last = bs(nums, target, false);
        vector<int> res;
        if(first == -1 || last == -1)
        {
            return res;
        }
        for(int i=first;i<=last;i++)
        {
            res.push_back(i);
        }
        return res;
    }

    int bs(vector<int> &nums, int target, bool bias)
    {
        int res = -1;
        int l = 0;
        int h =nums.size()-1;
        while(l <= h)
        {
            int m = l + (h - l) / 2;
            if(nums[m] == target)
            {
                res = m;
                if(bias)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else if(nums[m] > target)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return res;
    }
};