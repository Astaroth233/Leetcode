class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccur = binSearch(nums, target, true);
        int lastOccur = binSearch(nums, target, false);

        return {firstOccur, lastOccur};
    }

    int binSearch(vector<int> &nums, int target, bool Lbias)
    {
        int res = -1;
        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            {
                if(Lbias)
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
            else if(nums[mid] > target)
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