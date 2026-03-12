class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            {
                int first = checkpos(nums, target, low, high, true);
                int last = checkpos(nums, target, low, high, false);
                return {first, last};
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }

    int checkpos(vector<int>& a, int target,int left, int right, bool leftBias)
    {
        int low = left, high = right;
        int res = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target)
            {
                if(leftBias)
                {
                    res = mid;
                    high = mid - 1;
                }
                else
                {
                    res = mid;
                    low = mid + 1;
                }
            }
            else if(a[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};