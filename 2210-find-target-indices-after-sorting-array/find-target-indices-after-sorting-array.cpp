class Solution {
public:
    vector<int> res;
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums.size() - 1;

        while(l <= h)
        {
            int m = l + (h-l) / 2;
            if(nums[m] == target)
            {
                res.push_back(m);
                bs(nums, target, l, m-1);
                bs(nums, target, m+1, h);
                break;
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
        sort(res.begin(), res.end());
        return res;
    }

    void bs(vector<int> &nums, int target, int low, int high)
    {
        if(low > high)
        {
            return;
        }
        while(low <= high)
        {
            int m = low + (high-low) / 2;
            if(nums[m] == target)
            {
                res.push_back(m);
                bs(nums, target, low, m-1);
                bs(nums, target, m+1, high);
                break;

            }
            else if(nums[m] > target)
            {
                high = m - 1;
            }
            else
            {
                low = m + 1;
            }
        }
    }
};